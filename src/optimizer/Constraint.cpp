/*
  RTQL8, Copyright (c) 2011 Georgia Tech Graphics Lab
  All rights reserved.

  Author	Sehoon Ha
  Date		06/19/2011
*/

#include "Constraint.h"
using namespace std;
using namespace Eigen;

namespace optimizer {
    Constraint::Constraint(std::vector<Var*>& var)
        : mVariables(var){
        mIndex = 0; 
        // mWeight = vl_1; 
        // mWeight = VectorXd::Ones(1);
        mSlack = false;
        // mConstTerm = VectorXd::Zero(0);
        mEquality = 0;
        // mCompletion = vl_0;
        mConfigIndecies.push_back(0);
        mActive = true;
    }

    double Constraint::evalObj() {
        VectorXd constr = evalCon();
        return 0.5 * constr.dot(constr);
        /* return 0.5*dot(constr, constr); */
    }

} // namespace optimizer