#include <SYS/SYS_Math.h>
#include <UT/UT_DSOVersion.h>
#include <PRM/PRM_Include.h>
#include <OP/OP_Director.h>
#include <OP/OP_OperatorTable.h>
#include "my_lib1.h"

void newObjectOperator(OP_OperatorTable *table)
{
	table->addOperator(new OP_Operator("hdk_mylib", "MyLib",
									   MyLib1::myConstructor,
									   MyLib1::buildTemplatePair(nullptr),
									   MyLib1::theChildTableName,
									   0, 1,
									   nullptr));
}
auto MyLib1::myConstructor(OP_Network *network, const char *name, OP_Operator *op) -> OP_Node *
{
	return new MyLib1(network, name, op);
}
auto MyLib1::buildTemplatePair(OP_TemplatePair *prevstuff) -> OP_TemplatePair *
{
	static PRM_Name OBJJitter("jitter", "Jitter Scale");
	static std::array<PRM_Template, 2> templatelist =
			{
					PRM_Template(PRM_XYZ_J, 3, &OBJJitter, PRMoneDefaults),
					PRM_Template()
			};

	OP_TemplatePair *shake, *geo;

	shake = new OP_TemplatePair(templatelist.data(), prevstuff);
	geo = new OP_TemplatePair(OBJ_Geometry::getTemplateList(OBJ_PARMS_PLAIN), shake);

	return geo;
}

MyLib1::MyLib1(OP_Network *network, const char *string, OP_Operator *anOperator) : OBJ_Geometry(network, string, anOperator) {}
auto MyLib1::applyInputIndependentTransform(OP_Context &context, UT_DMatrix4 &mat) -> int
{
	return OBJ_Node::applyInputIndependentTransform(context, mat);
}
MyLib1::~MyLib1() = default;
