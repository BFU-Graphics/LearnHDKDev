#ifndef LEARNHDK_MY_LIB1_H
#define LEARNHDK_MY_LIB1_H

#include <OBJ/OBJ_Geometry.h>

class MyLib1 : public OBJ_Geometry
{
public:
	static auto myConstructor(OP_Network *network, const char *name, OP_Operator *op) -> OP_Node*;
	static auto buildTemplatePair(OP_TemplatePair *prevstuff) -> OP_TemplatePair*;

public:
	MyLib1(OP_Network *network, const char *name, OP_Operator *op);
	~MyLib1() override;

protected:
	auto applyInputIndependentTransform(OP_Context &context, UT_DMatrix4 &mat) -> int override;
};

#endif //LEARNHDK_MY_LIB1_H
