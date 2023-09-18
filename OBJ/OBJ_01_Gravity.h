#ifndef LEARNHDK_OBJ_01_GRAVITY_H
#define LEARNHDK_OBJ_01_GRAVITY_H

#include <OBJ/OBJ_Geometry.h>

class OBJ_01_Gravity : public OBJ_Geometry
{
public:
	// static constructor
	static auto myConstructor(OP_Network *network, const char *name, OP_Operator *op) -> OP_Node*;
	// static parameters
	static auto buildTemplatePair(OP_TemplatePair *prevstuff) -> OP_TemplatePair*;
	// constructor
	OBJ_01_Gravity(OP_Network *network, const char *name, OP_Operator *op);
};

#endif //LEARNHDK_OBJ_01_GRAVITY_H