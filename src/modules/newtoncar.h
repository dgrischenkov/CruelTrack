
#ifndef NEWTONCAR_H
#define NEWTONCAR_H

#include "../core/engine.h"

#define TIRE_COLLISION_ID		0x100
#define CHASSIS_COLLISION_ID	0x200

class CCar// : iObjects  
{
	struct CarTire
	{
		CarTire() {};
		virtual ~CarTire() {};
		void Setup (CCar *root, bool front, bool right);
		virtual void SetTirePhysics(const NewtonJoint* vehicle, void* tireId);
	

		dFloat m_width;
		dFloat m_radius;
		dFloat m_tireRefHeight;

		/*dVector m_brakeRefPosition;
		dMatrix m_tireOffsetMatrix;
		dMatrix m_axelMatrix;
		dMatrix m_suspentionTopMatrix;
		dMatrix m_suspentionBottomMatrix;
		dSceneNode *m_tireNode;
		dSceneNode *m_axelNode;
		dSceneNode *m_brakeNode;
		dSceneNode *m_topSuspNode;
		dSceneNode *m_bottomSuspNode;*/
	};


	struct FrontTire: public CarTire
	{
		FrontTire() { m_steer = 0.0f; }
		void SetSteer (dFloat value) { m_steer = value;	}
		void SetTorque (dFloat value) {	m_torque = value; }
		void SetBrakes (dFloat brake) {	m_brakes = brake; }
		virtual void SetTirePhysics(const NewtonJoint* vehicle, void* tireId);
		dFloat m_steer;
		dFloat m_torque;
		dFloat m_brakes;
	};
	
	struct RearTire: public CarTire
	{
		RearTire() { m_torque = 0.0f; }
		void SetTorque (dFloat value) {	m_torque = value; }
		void SetBrakes (dFloat brake) {	m_brakes = brake; }
		virtual void SetTirePhysics(const NewtonJoint* vehicle, void* tireId);
		dFloat m_torque;
		dFloat m_brakes;
	};

public:
	
	CCar(const char* fileName, NewtonWorld* nWorld, const matrix4 &matrix);
	virtual ~CCar();

	virtual void SetSteering(dFloat value);
	virtual void SetTireTorque(dFloat torque);
	virtual void SetApplyHandBrakes (dFloat value);
	virtual void SetControl(int index, dFloat value) {};

	virtual void setObjPosition(const vector3df &vector);

	vector3df	getPosition();
	vector3df	getDirection();

	dFloat GetSpeed() const;

private:
	
	static void DestroyVehicle (const NewtonBody* body);
	static void ForceAndTorque(const NewtonBody* body);
	static void Transform (const NewtonBody* body, const dFloat* matrix);
	static void TireUpdate (const NewtonJoint* vehicle);

	RearTire		m_tire_rear_l;
	RearTire		m_tire_rear_r;
	FrontTire		m_tire_front_l;
	FrontTire		m_tire_front_r;

	NewtonBody*		vehicle_body;
	NewtonJoint*	vehicle_joint;

	dFloat			vehicle_mass;

	IAnimatedMeshSceneNode *chassis;
	IAnimatedMeshSceneNode *(tire[4]);

	vector3df		pos;
};

#endif
