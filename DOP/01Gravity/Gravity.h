#ifndef LEARNHDKDEV_GRAVITY_H
#define LEARNHDKDEV_GRAVITY_H

#include <SIM/SIM_SingleSolver.h>
#include <SIM/SIM_OptionsUser.h>
#include <SIM/SIM_Utils.h>
#include <UT/UT_DSOVersion.h> // must include

class GravitySolver : public SIM_SingleSolver, public SIM_OptionsUser
{
public:
	explicit GravitySolver(const SIM_DataFactory *factory);

protected:
	auto solveSingleObjectSubclass(SIM_Engine &engine, SIM_Object &object, SIM_ObjectArray &feedbacktoobjects, const SIM_Time &timestep, bool newobject) -> SIM_Result override;

private:
	static auto getMyOwnSolverDescription() -> const SIM_DopDescription *;

	DECLARE_STANDARD_GETCASTTOTYPE();
	DECLARE_DATAFACTORY(GravitySolver,
						SIM_SingleSolver,
						"Gravity Solver",
						getMyOwnSolverDescription());
};

#endif //LEARNHDKDEV_GRAVITY_H
