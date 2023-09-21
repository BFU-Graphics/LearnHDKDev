#ifndef LEARNHDK_OBJ_01_GRAVITY_H
#define LEARNHDK_OBJ_01_GRAVITY_H

#include <OBJ/OBJ_Geometry.h>
#include <UT/UT_DSOVersion.h>

class OBJ_01_Gravity : public OBJ_Geometry
{
public:
	// static constructor
	static auto myConstructor(OP_Network *network, const char *name, OP_Operator *op) -> OP_Node*;
	// static parameters
	static auto buildTemplatePair(OP_TemplatePair *prevstuff) -> OP_TemplatePair*;
	// constructor
	OBJ_01_Gravity(OP_Network *network, const char *name, OP_Operator *op);

protected:
	auto applyInputIndependentTransform(OP_Context &context, UT_DMatrix4 &mat) -> int override;
};

#endif //LEARNHDK_OBJ_01_GRAVITY_H
