/*    Copyright (c) 2010-2012 Delft University of Technology.
 *
 *    This software is protected by national and international copyright.
 *    Any unauthorized use, reproduction or modification is unlawful and
 *    will be prosecuted. Commercial and non-private application of the
 *    software in any form is strictly prohibited unless otherwise granted
 *    by the authors.
 *
 *    The code is provided without any warranty; without even the implied
 *    warranty of merchantibility or fitness for a particular purpose.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      101111    E. Iorfida        First creation of code.
 *      101118    E. Iorfida        Added algorithm implementation.
 *      101121    E. Iorfida        Modified algorithm and added Doxygen comments.
 *      101216    E. Iorfida        Modified punctuation.
 *      110111    E. Iorfida        Deleted useless lines, and modified punctuation.
 *      110111    K. Kumar          Updated based on changes to .h file; changed do-while loop to
 *                                  for loop to prevent infinite loop; added "End of file."
 *      110119    K. Kumar          Updated code to work with adaptor and abstract base
 *                                  implementation so that pointer-to-member functions are not
 *                                  required; changed filename.
 *      110124    K. Kumar          Added cerr statement for when loop does not converge.
 *      110905    S. Billemont      Reorganized includes.
 *                                  Moved (con/de)structors and getter/setters to header.
 *
 *    References
 *
 */

#include "Tudat/Mathematics/RootFindingMethods/newtonRaphson.h"
#include <cmath>

namespace tudat
{

// Using declarations.
using std::cerr;
using std::endl;

//! Set adaptor class for Newton-Raphson.
void NewtonRaphson::setNewtonRaphsonAdaptor( NewtonRaphsonBase* pointerToNewtonRaphsonBase )
{
    pointerToNewtonRaphsonBase_ = pointerToNewtonRaphsonBase;
    pointerToGlobalFunction_ = NULL;
    pointerToGlobalFirstDerivativeFunction_ = NULL;
}

//! Execute Newton-Raphson method.
void NewtonRaphson::execute( )
{
    // Algorithm implementation.
    // First step.
    nextValueOfRoot_ = initialGuessOfRoot_;

    for ( unsigned int i = 0; i < maximumNumberOfIterations_; i++ )
    {
        // Update current value of root.
        currentValueOfRoot_ = nextValueOfRoot_;

        // Compute next value of root using the following algorithm:
        // x_n+1 = x_n - F(x_n)/F'(x_n).

        // Check if necessary global mathematical functions are set.
        if ( pointerToGlobalFunction_ && pointerToGlobalFirstDerivativeFunction_ )
        {
            // Use pointers to global functions.
            nextValueOfRoot_ = currentValueOfRoot_
                    - ( *pointerToGlobalFunction_ )( currentValueOfRoot_ )
                    / ( *pointerToGlobalFirstDerivativeFunction_ )( currentValueOfRoot_ );
        }

        // Else check if class with member mathematical functions is set.
        else if ( pointerToNewtonRaphsonBase_ )
        {
            // Use pointers to member functions.
            nextValueOfRoot_ = currentValueOfRoot_
                    - pointerToNewtonRaphsonBase_->computeFunction( currentValueOfRoot_ )
                    /  pointerToNewtonRaphsonBase_->computeFirstDerivativeFunction(
                        currentValueOfRoot_ );
        }

        // Check if difference between successive iterations of the
        // root-finding method satisfies the set tolerance and break from loop
        // if it is satisfied.
        if ( std::fabs( nextValueOfRoot_ - currentValueOfRoot_ ) <= tolerance_ )
        {
            break;
        }

        // If the end of the loop is reached before the tolerance is satisfied,
        // print cerr statement to indicate to the user that there method did
        // not converge.
        if ( i == maximumNumberOfIterations_ - 1 )
        {
            // Reset values of root to initialized values.
            currentValueOfRoot_ = -0.0;
            nextValueOfRoot_ = -0.0;

            cerr << "The Newton-Raphson algorithm did not converge after "
                 << maximumNumberOfIterations_ << " iterations." << endl;
        }
    }
}

//! Overload ostream to print class information.
std::ostream& operator<<( std::ostream& stream, NewtonRaphson& newtonRaphson )
{
    stream << "This is a NewtonRaphson object" << endl;
    stream << "The maximum number of iterations is set to: "
           << newtonRaphson.getMaximumNumberOfIterations( )
           << "The tolerance is set to: " << newtonRaphson.getTolerance( )
           << "The initial guess of root is set to: " << newtonRaphson.initialGuessOfRoot_
           << "The computed root is: " << newtonRaphson.getComputedRootOfFunction( ) << endl;

    // Return stream.
    return stream;
}

} // namespace tudat