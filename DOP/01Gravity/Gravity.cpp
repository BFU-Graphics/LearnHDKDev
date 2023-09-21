#include "Gravity.h"
#include <PRM/PRM_Include.h>
#include <SIM/SIM_DopDescription.h>

auto GravitySolver::solveSingleObjectSubclass(SIM_Engine &engine, SIM_Object &object, SIM_ObjectArray &feedbacktoobjects, const SIM_Time &timestep, bool newobject) -> SIM_Solver::SIM_Result
{
	return SIM_SOLVER_SUCCESS;
}

auto GravitySolver::getMyOwnSolverDescription() -> const SIM_DopDescription *
{
	static PRM_Name	 param1("param1", "Param 1");
	static PRM_Name	 param2("param2", "Param 2");
	static PRM_Name	 param3("param3", "Param 3");

	static PRM_Template	 theTemplates[] = {
			PRM_Template(PRM_INT,		3, &param1, PRMtenDefaults),
			PRM_Template(PRM_XYZ,		3, &param2, PRMzeroDefaults),
			PRM_Template(PRM_XYZ,		3, &param3, PRMoneDefaults),
			PRM_Template()
	};

	static SIM_DopDescription	 theDopDescription(true,
													"hdk_mygravitysolver",
													"My Gravity Solver",
													"MyGravitySolver",
													classname(),
													theTemplates);

	return &theDopDescription;
}
GravitySolver::GravitySolver(const SIM_DataFactory *factory) : SIM_SingleSolver(factory), SIM_OptionsUser(this) {}
