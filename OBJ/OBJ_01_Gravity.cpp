#include "OBJ_01_Gravity.h"

#include <PRM/PRM_Include.h>
#include <OP/OP_Director.h>

void newObjectOperator(OP_OperatorTable *table)
{
	table->addOperator(
			new OP_Operator(
					"hdk_gravity",
					"Gravity",
					OBJ_01_Gravity::myConstructor,
					OBJ_01_Gravity::buildTemplatePair(nullptr),
					1,
					1,
					nullptr,
					OP_FLAG_GENERATOR
			)
	);
}

auto OBJ_01_Gravity::myConstructor(OP_Network *network, const char *name, OP_Operator *op) -> OP_Node * { return new OBJ_01_Gravity(network, name, op); }
auto OBJ_01_Gravity::buildTemplatePair(OP_TemplatePair *prevstuff) -> OP_TemplatePair *
{
	return nullptr;
}
OBJ_01_Gravity::OBJ_01_Gravity(OP_Network *network, const char *name, OP_Operator *op) : OBJ_Geometry(network, name, op) {}
auto OBJ_01_Gravity::applyInputIndependentTransform(OP_Context &context, UT_DMatrix4 &mat) -> int
{
	// call OBJ_Geometry::applyInputIndependentTransform() so that we don't lose any information
	int modified = OBJ_Geometry::applyInputIndependentTransform(context, mat);
	if (error() >= UT_ERROR_ABORT)
	{
		// don't do anything since an error has occurred.
		return modified;
	}

	fpreal t = context.getTime(); // extract time from OP_Context

	return modified;
}
