
#include "newtoncar.h"


//#define MAX_TORQUE (2400.0f)
//#define BUFFER_SIZE	20000

// set frequency to 2 hertz
//#define SUSPENSION_FREQUENCE	(2.0f)
#define SUSPENSION_LENGTH		(1.5f)

//#define MAX_STEER_ANGLE (30.0f * 3.1416f / 180.0f)


CCar::CCar(const char* fileName, NewtonWorld* nWorld, const matrix4 &matrix)
{
	chassis = smgr->addAnimatedMeshSceneNode( smgr->getMesh("models/car.3ds"));
	chassis->setMaterialTexture(0, driver->getTexture("models/truck.png"));
    chassis->setMaterialFlag(EMF_LIGHTING, false);
	chassis->addShadowVolumeSceneNode(-1,false);
	
    aabbox3d<f32> bb = chassis->getTransformedBoundingBox();
	vector3df box_size(	bb.MaxEdge.X-bb.MinEdge.X, 
						bb.MaxEdge.Y-bb.MinEdge.Y,
						bb.MaxEdge.Z-bb.MinEdge.Z);
    
	NewtonCollision* collision = NewtonCreateBox(nWorld,
        box_size.X, box_size.Y, box_size.Z, 0);//&matrix.M[0]);
	
	dFloat Ixx;
	dFloat Iyy;
	dFloat Izz;
	dFloat Mass;

	//dInt32 vertexCount; 
	//dSceneNode* bodyPart;	
//	char fullPathName[256];
	//dLoaderContext context;

	//SetMatrix (matrix);

	// create the collision geometry
	//dMatrix localMatrix (bodyPart->CalcGlobalMatrix (this));

	//collision = NewtonCreateConvexHull (nWorld, vertexCount, &vertex[0].m_x, sizeof (dVector), &localMatrix[0][0]);
	
	vehicle_body = NewtonCreateBody (nWorld, collision);
	NewtonBodySetUserData(vehicle_body, this);
	
	vehicleID = NewtonMaterialCreateGroupID(nWorld);
	NewtonBodySetMaterialGroupID (vehicle_body, vehicleID);	

	NewtonBodySetDestructorCallback (vehicle_body, DestroyVehicle);
	NewtonBodySetTransformCallback (vehicle_body, Transform);
	NewtonBodySetForceAndTorqueCallback (vehicle_body, ForceAndTorque);

	NewtonBodySetAutoFreeze (vehicle_body, 0);
	NewtonWorldUnfreezeBody (nWorld, vehicle_body);

	/*dVector origin;
	dVector inertia;

	NewtonConvexCollisionCalculateInertialMatrix (vehicleCollision, &inertia[0], &origin[0]);	

	mass = VEHICLE_MASS;
	Ixx = mass * inertia[0];
	Iyy = mass * inertia[1];
	Izz = mass * inertia[2];
	*/
	
	vehicle_mass = 1000.0f;
	Mass = vehicle_mass/2;
	Ixx = Mass * (box_size.Y * box_size.Y + box_size.Z * box_size.Z) / 12;
	Iyy = Mass * (box_size.X * box_size.X + box_size.Z * box_size.Z) / 12;
	Izz = Mass * (box_size.X * box_size.X + box_size.Y * box_size.Y) / 12;

	NewtonBodySetMassMatrix (vehicle_body, Mass, Ixx, Iyy, Izz);

	vector3df origin;
	NewtonBodyGetCentreOfMass(vehicle_body, &origin.X);
	origin.Y -= box_size.Y/2;
	NewtonBodySetCentreOfMass (vehicle_body, &origin.X);
	
	NewtonBodySetMatrix (vehicle_body, &matrix.M[0]);

	NewtonReleaseCollision (nWorld, collision);	

	vector3df updir(0,1,0);
	vehicle_joint = NewtonConstraintCreateVehicle (nWorld, &updir.X, vehicle_body); 

	NewtonVehicleSetTireCallback (vehicle_joint, TireUpdate);
 	NewtonBodySetLinearDamping (vehicle_body, 0.0f);

	m_tire_rear_r.Setup (this, 0,1);
	m_tire_rear_l.Setup (this, 0,0);
	m_tire_front_r.Setup (this, 1,1);
	m_tire_front_l.Setup (this, 1,0);

	//delete[] vertex;
}

CCar::~CCar()
{
	chassis->remove( );
	tire[0]->remove( );
	tire[1]->remove( );
	tire[2]->remove( );
	tire[3]->remove( );
    NewtonDestroyBody(nWorld, vehicle_body);
}

void CCar::setObjPosition(const vector3df &vector)
{
    matrix4 m;
    NewtonBodyGetMatrix(vehicle_body, m.M);
    vector3df v=m.getTranslation( );
    v+=vector;
    m.setTranslation( v );
    NewtonBodySetMatrix(vehicle_body, m.M);
}

void CCar::DestroyVehicle (const NewtonBody* body)
{
	CCar* vehicle;
	vehicle = (CCar*) NewtonBodyGetUserData (body);
	delete vehicle;
}


void CCar::ForceAndTorque(const NewtonBody* body)
{
	dFloat Ixx;
	dFloat Iyy;
	dFloat Izz;
	dFloat mass;
	CCar* car;

	NewtonBodyGetMassMatrix (body, &mass, &Ixx, &Iyy, &Izz);
	
	car = (CCar*) NewtonBodyGetUserData(body);
	
	vector3df force(0.0f, mass * -10, 0.0f);
	NewtonBodyAddForce(body, &force.X);

	dFloat m_torque = car->m_tire_rear_l.m_torque;
	dFloat m_steer = RADTODEG(car->m_tire_front_l.m_steer);

	if (key_input['w']){
		m_torque+=1.5f;
		//m_torque = 100;
    } else if (key_input['s']){
        m_torque-=1.0f;
		//m_torque = -80;
    } else	{ m_torque = 0; }
	if (key_input['d']){
        m_steer+=0.2f;
    } else if (key_input['a']){
        m_steer-=0.2f;
	} else	{ m_steer /= 1.1f; }
	if (key_input[' ']){
		//m_torque=0;
		//m_steer=0;
		car->SetApplyHandBrakes(1.0f);
	} else { car->SetApplyHandBrakes(0.0f);	}

	if(m_torque>700)m_torque=700;
	if(m_torque<-500)m_torque=-500;
        
	if(m_steer>20)m_steer=20;
	if(m_steer<-20)m_steer=-20;

	m_steer = DEGTORAD(m_steer);

	car->SetSteering(m_steer);
	car->SetTireTorque(m_torque);
}


void CCar::Transform (const NewtonBody* body, const dFloat* matrix)
{
	CCar *vehicle = (CCar*) NewtonBodyGetUserData (body);

	matrix4 m; for (int i=0; i<16; i++) m.M[i]=matrix[i];
    vehicle->chassis->setRotation( m.getRotationDegrees( ) );
    vehicle->chassis->setPosition( m.getTranslation( ) );
	vehicle->pos = m.getTranslation();
	
	void* tireId;
	
	int j=0;
	for (tireId = NewtonVehicleGetFirstTireID (vehicle->vehicle_joint); tireId; tireId = NewtonVehicleGetNextTireID (vehicle->vehicle_joint, tireId))
	{
		NewtonVehicleGetTireMatrix(vehicle->vehicle_joint, tireId, &m.M[0]);
		vehicle->tire[j]->setRotation( m.getRotationDegrees( ) );
		vehicle->tire[j]->setPosition( m.getTranslation( ) );
		j++;
	}
}


dFloat CCar::GetSpeed() const
{
	return 1.0f;
}

void CCar::SetSteering(dFloat value)
{
	m_tire_front_l.SetSteer (value);
	m_tire_front_r.SetSteer (value);
}


void CCar::SetTireTorque(dFloat value)
{
	m_tire_rear_l.SetTorque (value);
	m_tire_rear_r.SetTorque (value);

	m_tire_front_l.SetTorque (value);
	m_tire_front_r.SetTorque (value);
}


void CCar::SetApplyHandBrakes (dFloat value)
{
	m_tire_rear_l.SetBrakes (value);
	m_tire_rear_r.SetBrakes (value);

	m_tire_front_l.SetBrakes (value);
	m_tire_front_r.SetBrakes (value);
}



void CCar::TireUpdate (const NewtonJoint* vehicle)
{
	void* id;
	CarTire* wheel;

	for (id = NewtonVehicleGetFirstTireID (vehicle); id; id = NewtonVehicleGetNextTireID (vehicle, id))
	{
		wheel = (CarTire*) NewtonVehicleGetTireUserData (vehicle, id);
		wheel->SetTirePhysics (vehicle, id);
	}
}


void CCar::CarTire::Setup (CCar *root, bool front, bool right)
{
	dFloat tireMass; 
	dFloat tireSuspesionShock;
	dFloat tireSuspesionSpring; 

	tireMass = 2.0f; 
	tireSuspesionShock = 1.0f;
	tireSuspesionSpring = 1.0f; 

	for (int i=0; i<4; i++)
	{
		root->tire[i] = smgr->addAnimatedMeshSceneNode( smgr->getMesh("models/wheel.3ds"));
		root->tire[i]->setMaterialTexture(0, driver->getTexture("models/wheel.tga"));
		root->tire[i]->setMaterialFlag(EMF_LIGHTING, false);
		root->tire[i]->addShadowVolumeSceneNode(-1,false);
	}
	
	aabbox3d<f32> bb = root->tire[0]->getTransformedBoundingBox();
	vector3df box_size(	bb.MaxEdge.X-bb.MinEdge.X, 
						bb.MaxEdge.Y-bb.MinEdge.Y,
						bb.MaxEdge.Z-bb.MinEdge.Z);

	
	m_width = box_size.X*2;
	m_radius = box_size.Y/2;
	
	// set the tire visual offset matrix
	//m_tireOffsetMatrix = m_tireNode->GetParent()->CalcGlobalMatrix (root).Inverse();

	matrix4 tirePosition;

	float s_width = 1.4f;
	float s_length = 1.75f;
	float s_susp = - 1.5f;
	//float s_susp = -SUSPENSION_LENGTH;

	if((front==1)&&(right==1))
	{
		tirePosition.setTranslation(vector3df(s_width,s_susp,s_length));
	} else 
		if((front==1)&&(right==0))
	{
		tirePosition.setTranslation(vector3df(-s_width,s_susp,s_length));
	} else 
		if((front==0)&&(right==1))
	{
		tirePosition.setTranslation(vector3df(s_width,s_susp,-s_length));
	} else 
		if((front==0)&&(right==0))
	{
		tirePosition.setTranslation(vector3df(-s_width,s_susp,-s_length));
	}
	
	vector3df tirePin(1.0f, 0.0f, 0.0f);

	dFloat x = SUSPENSION_LENGTH;
	tireSuspesionSpring = (50.0f * ABS(-10.0f)) / x;
	//tireSuspesionSpring = (100.0f * ABS(GRAVITY)) / x;

	float w = SQRT(tireSuspesionSpring);

	tireSuspesionShock = 1.0f * w;

	//s_susp = m_radius*2;
	s_susp = SUSPENSION_LENGTH;
	NewtonVehicleAddTire (root->vehicle_joint, &tirePosition.M[0], &tirePin.X, tireMass, m_width, m_radius, 
						  tireSuspesionShock, tireSuspesionSpring, s_susp, this, TIRE_COLLISION_ID);
}



void CCar::CarTire::SetTirePhysics(const NewtonJoint* vehicle, void* tireId)
{
}

void CCar::RearTire::SetTirePhysics(const NewtonJoint* vehicle, void* tireId)
{
	NewtonVehicleSetTireTorque (vehicle, tireId, m_torque);

	if (m_brakes > 0.0f) {
		dFloat speed;
		dFloat brakeAcceleration;

		brakeAcceleration = NewtonVehicleTireCalculateMaxBrakeAcceleration (vehicle, tireId);

		NewtonVehicleTireSetBrakeAcceleration (vehicle, tireId, brakeAcceleration, 500.0f);

		speed = NewtonVehicleGetTireLongitudinalSpeed (vehicle, tireId);
		NewtonVehicleSetTireMaxSideSleepSpeed (vehicle, tireId, speed * 0.1f);
	}
}


void CCar::FrontTire::SetTirePhysics(const NewtonJoint* vehicle, void* tireId)
{
/*	dFloat currSteerAngle;

	currSteerAngle = NewtonVehicleGetTireSteerAngle (vehicle, tireId);
	NewtonVehicleSetTireSteerAngle(vehicle, tireId, currSteerAngle + (m_steer - currSteerAngle) * 0.035f);
*/
	NewtonVehicleSetTireSteerAngle (vehicle, tireId, m_steer);

	NewtonVehicleSetTireTorque (vehicle, tireId, m_torque);

	if (m_brakes > 0.0f) {
		dFloat speed;
		dFloat brakeAcceleration;

		brakeAcceleration = NewtonVehicleTireCalculateMaxBrakeAcceleration (vehicle, tireId);

		NewtonVehicleTireSetBrakeAcceleration (vehicle, tireId, brakeAcceleration, 500.0f);

		speed = NewtonVehicleGetTireLongitudinalSpeed (vehicle, tireId);
		NewtonVehicleSetTireMaxSideSleepSpeed (vehicle, tireId, speed * 0.1f);
	}
}

vector3df	CCar::getPosition()
{
	return pos;
}

vector3df	CCar::getDirection()
{
	vector3df	vec;
	NewtonBodyGetVelocity(vehicle_body, &vec.X);
	
	return vec;
}
