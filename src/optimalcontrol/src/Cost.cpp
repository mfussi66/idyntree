// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause
/*
 * Originally developed for Prioritized Optimal Control (2014)
 * Refactored in 2018.
 * Design inspired by
 * - ACADO toolbox (http://acado.github.io)
 * - ADRL Control Toolbox (https://adrlab.bitbucket.io/ct/ct_doc/doc/html/index.html)
 */

#include <iDynTree/Cost.h>
#include <iDynTree/Core/Utils.h>
#include <sstream>

namespace iDynTree {
    namespace optimalcontrol{
        Cost::Cost(const std::string &costName)
            :m_costName(costName)
        { }

        Cost::~Cost()
        { }

        const std::string &Cost::name() const
        {
            return m_costName;
        }

        bool Cost::costFirstPartialDerivativeWRTState(double /*time*/, const VectorDynSize &/*state*/, const VectorDynSize &/*control*/, VectorDynSize &/*partialDerivative*/)
        {
            std::ostringstream errorMsg;
            errorMsg << "Method not implemented for cost "<< name() << std::endl;
            reportError("Cost", "costFirstPartialDerivativeWRTState", errorMsg.str().c_str());
            return false;
        }

        bool Cost::costFirstPartialDerivativeWRTControl(double /*time*/, const VectorDynSize &/*state*/, const VectorDynSize &/*control*/, VectorDynSize &/*partialDerivative*/)
        {
            std::ostringstream errorMsg;
            errorMsg << "Method not implemented for cost "<< name() << std::endl;
            reportError("Cost", "costFirstPartialDerivativeWRTControl", errorMsg.str().c_str());
            return false;
        }

        bool Cost::costSecondPartialDerivativeWRTState(double /*time*/, const VectorDynSize &/*state*/, const VectorDynSize &/*control*/, MatrixDynSize &/*partialDerivative*/)
        {
            std::ostringstream errorMsg;
            errorMsg << "Method not implemented for cost "<< name() << std::endl;
            reportError("Cost", "costSecondPartialDerivativeWRTState", errorMsg.str().c_str());
            return false;
        }

        bool Cost::costSecondPartialDerivativeWRTControl(double /*time*/, const VectorDynSize &/*state*/, const VectorDynSize &/*control*/, MatrixDynSize &/*partialDerivative*/)
        {
            std::ostringstream errorMsg;
            errorMsg << "Method not implemented for cost "<< name() << std::endl;
            reportError("Cost", "costSecondPartialDerivativeWRTControl", errorMsg.str().c_str());
            return false;
        }

        bool Cost::costSecondPartialDerivativeWRTStateControl(double /*time*/, const VectorDynSize &/*state*/, const VectorDynSize &/*control*/, MatrixDynSize &/*partialDerivative*/)
        {
            std::ostringstream errorMsg;
            errorMsg << "Method not implemented for cost "<< name() << std::endl;
            reportError("Cost", "costSecondPartialDerivativeWRTStateControl", errorMsg.str().c_str());
            return false;
        }

        bool Cost::costSecondPartialDerivativeWRTStateSparsity(SparsityStructure &/*stateSparsity*/)
        {
            return false;
        }

        bool Cost::costSecondPartialDerivativeWRTStateControlSparsity(SparsityStructure &/*stateControlSparsity*/)
        {
            return false;
        }

        bool Cost::costSecondPartialDerivativeWRTControlSparsity(SparsityStructure &/*controlSparsity*/)
        {
            return false;
        }

    }

}
