#include "my_lib1.h"
#include <GU/GU_Detail.h>
#include <OP/OP_Operator.h>
#include <OP/OP_OperatorTable.h>
#include <UT/UT_DSOVersion.h>

MyLib1::MyLib1(OP_Network *parent, const char *name, OP_Operator *entry) : SOP_Node(parent, name, entry) {}

auto MyLib1Params() -> PRM_Template*
{
	return nullptr;
}

void newSopOperator(OP_OperatorTable *table)
{
	table->addOperator(new OP_Operator(
			"MyOperator",                    // name
			"MyOperator",                   // display name
			[](OP_Network *net, const char *name, OP_Operator *op) -> OP_Node* {
				return new MyLib1(net, name, op);
			},                             // constructor
			MyLib1Params(),                   // parameters
			0,                             // min # of sources
			0,                             // max # of sources
			nullptr,                       // local variables
			OP_FLAG_GENERATOR              // generates data
	));
}

auto MyLib1::test_func(OP_Context &context) -> OP_ERROR
{
	return UT_ERROR_FATAL;
}

auto MyLib1::cookMySop(OP_Context &context) -> OP_ERROR
{
	gdp->clearAndDestroy();
	return error();
}
