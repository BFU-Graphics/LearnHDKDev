#ifndef LEARNHDK_MY_LIB1_H
#define LEARNHDK_MY_LIB1_H

#include <SOP/SOP_Node.h>

class MyLib1 : public SOP_Node
{
public:
	MyLib1(OP_Network *parent, const char *name, OP_Operator *entry);
	virtual auto test_func(OP_Context &context) -> OP_ERROR;

protected:
	auto cookMySop(OP_Context &context) -> OP_ERROR override;
};

#endif //LEARNHDK_MY_LIB1_H
