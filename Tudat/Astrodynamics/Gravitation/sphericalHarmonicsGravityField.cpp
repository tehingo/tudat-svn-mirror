/*    Copyright (c) 2010-2013, Delft University of Technology
 *    All rights reserved.
 *
 *    Redistribution and use in source and binary forms, with or without modification, are
 *    permitted provided that the following conditions are met:
 *      - Redistributions of source code must retain the above copyright notice, this list of
 *        conditions and the following disclaimer.
 *      - Redistributions in binary form must reproduce the above copyright notice, this list of
 *        conditions and the following disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *      - Neither the name of the Delft University of Technology nor the names of its contributors
 *        may be used to endorse or promote products derived from this software without specific
 *        prior written permission.
 *
 *    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
 *    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *    COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 *    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 *    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 *    OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *    Changelog
 *      YYMMDD    Author            Comment
 *      101117    K. Kumar          File created.
 *      101214    K. Kumar          Updated getGradientOfPotential( ) and getLaplacianOfPotential( ).
 *      101215    K. Kumar          Simplified getGradientOfPotential( ) and
 *                                  getLaplacianOfPotential( ).
 *      101216    K. Kumar          Updated functions to use position of origin for relative
 *                                  position.
 *      110106    K. Kumar          Added set/get functions for degree and order of expansion.
 *      110202    K. Kumar          Updated code to make use of the CartesianPositionElements
 *                                  class.
 *      110204    K. Kumar          Removed "vector" from naming.
 *      110310    K. Kumar          Changed naming from Laplacian to gradient tensor.
 *      110805    K. Kumar          Added predefined functionality with WGS-72 and WGS-84 predefined
 *                                  predefined Earth gravity fields.
 *      120326    D. Dirkx          Changed raw pointers to shared pointers.
 *
 *    References
 *      Vallado, D. A., Crawford, P., Hujsak, R., & Kelso, T. Revisiting Spacetrack Report #3:
 *          Rev 1, Proceedings of the AIAA/AAS Astrodynamics Specialist Conference. Keystone, CO,
 *          2006.
 *
 *    Notes
 *
 */

#include <cmath>

#include "Tudat/Astrodynamics/Gravitation/sphericalHarmonicsGravityField.h"

namespace tudat
{
namespace gravitation
{

//! Set predefined spherical harmonics gravity field settings.
void SphericalHarmonicsGravityField::setPredefinedSphericalHarmonicsGravityFieldSettings(
    BodiesWithPredefinedSphericalHarmonicsGravityFields
    bodyWithPredefinedSphericalHarmonicsGravityField )
{
    using std::pow;

    // Select body with prefined central gravity field.
    switch( bodyWithPredefinedSphericalHarmonicsGravityField )
    {
    case earthWorldGeodeticSystem72:

        // Reference: Table 2 in (Vallado, D.A., et al., 2006).

        // Set gravitational parameter [m^3 s^-2].
        gravitationalParameter_ = 398600.8e9;

        // Set reference radius.
        referenceRadius_ = 6378.135e3;

        // Set J2 coefficient.
        j2SphericalHarmonicsGravityFieldCoefficient_ = 0.001082616;

        // Set J3 coefficient.
        j3SphericalHarmonicsGravityFieldCoefficient_ = -0.00000253881;

        // Set J4 coefficient.
        j4SphericalHarmonicsGravityFieldCoefficient_ = -0.00000165597;

        break;

    case earthWorldGeodeticSystem84:

        // Reference: Table 3 in (Vallado, D.A., et al., 2006).

        // Set gravitational parameter [m^3 s^-2].
        gravitationalParameter_ = 398600.4418e9;

        // Set reference radius.
        referenceRadius_ = 6378.137e3;

        // Set J2 coefficient.
        j2SphericalHarmonicsGravityFieldCoefficient_ = 0.00108262998905;

        // Set J3 coefficient.
        j3SphericalHarmonicsGravityFieldCoefficient_ = -0.00000253215306;

        // Set J4 coefficient.
        j4SphericalHarmonicsGravityFieldCoefficient_ = -0.00000161098761;

        break;

    default:

        // Print cerr statement.
        std::cerr << "Desired predefined spherical harmonics gravity field does not exist."
                  << std::endl;
    };
}

//! Get gradient tensor of the gravitational potential.
Eigen::Matrix3d SphericalHarmonicsGravityField::
        getGradientTensorOfPotential( const Eigen::Vector3d& position )
{
    using std::pow;

    // Declare identity matrix for computations.
    Eigen::Matrix3d identityMatrix_ = Eigen::Matrix3d::Identity( 3, 3 );

    // Compute relative position.
    relativePosition_ = position - positionOfOrigin_;

    // Compute and return gradient tensor of potential.
    return gravitationalParameter_ / pow( relativePosition_.norm( ), 5.0 )
            * ( ( 3.0 * relativePosition_ * relativePosition_.transpose( ) )
                - ( relativePosition_.squaredNorm( ) * identityMatrix_ ) );
}

//! Overload ostream to print class information.
std::ostream& operator<<( std::ostream& stream,
                          SphericalHarmonicsGravityField&
                          sphericalHarmonicsGravityField )
{
    using std::endl;

    stream << "This is a SphericalHarmonicsGravityField object." << endl;
    stream << "The gravitational parameter is set to: "
           << sphericalHarmonicsGravityField.getGravitationalParameter( ) << endl;
    stream << "The origin of the gravity field is set to: "
           << sphericalHarmonicsGravityField.getOrigin( ) << endl;
    stream << "The degree of expansion of the spherical harmonics series is set to : "
           << sphericalHarmonicsGravityField.getDegreeOfExpansion( ) << endl;
    stream << "The order of expansion of the spherical harmonics series is set to: "
           << sphericalHarmonicsGravityField.getOrderOfExpansion( ) << endl;
    stream << "The reference radius is set to: "
           << sphericalHarmonicsGravityField.getReferenceRadius( ) << endl;

    // Return stream.
    return stream;
}

} // namespace gravitation
} // namespace tudat
