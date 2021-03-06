 #    Copyright (c) 2010-2013, Delft University of Technology
 #    All rights reserved.
 #
 #    Redistribution and use in source and binary forms, with or without modification, are
 #    permitted provided that the following conditions are met:
 #      - Redistributions of source code must retain the above copyright notice, this list of
 #        conditions and the following disclaimer.
 #      - Redistributions in binary form must reproduce the above copyright notice, this list of
 #        conditions and the following disclaimer in the documentation and/or other materials
 #        provided with the distribution.
 #      - Neither the name of the Delft University of Technology nor the names of its contributors
 #        may be used to endorse or promote products derived from this software without specific
 #        prior written permission.
 #
 #    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
 #    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 #    MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 #    COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 #    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 #    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 #    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 #    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 #    OF THE POSSIBILITY OF SUCH DAMAGE.
 #
 #    Changelog
 #      YYMMDD    Author            Comment
 #      110820    S.M. Persson      File created.
 #      111025    K. Kumar          Adapted file to work with Revision 194.
 #      111026    K. Kumar          Adapted file so all headers show in project tree in Qt Creator.
 #
 #    References
 #
 #    Notes
 #

# Set the source files.
set(AERODYNAMICS_SOURCES
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamicMoment.cpp"
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamics.cpp"
  "${SRCROOT}${AERODYNAMICSDIR}/exponentialAtmosphere.cpp"
  "${SRCROOT}${AERODYNAMICSDIR}/hypersonicLocalInclinationAnalysis.cpp"
  "${SRCROOT}${AERODYNAMICSDIR}/tabulatedAtmosphere.cpp"
)

# Set the header files.
set(AERODYNAMICS_HEADERS 
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamicAcceleration.h"
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamicCoefficientGenerator.h"
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamicCoefficientInterface.h"
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamicForce.h"
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamicMoment.h"
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamicRotationalAcceleration.h"
  "${SRCROOT}${AERODYNAMICSDIR}/aerodynamics.h"
  "${SRCROOT}${AERODYNAMICSDIR}/atmosphereModel.h"
  "${SRCROOT}${AERODYNAMICSDIR}/exponentialAtmosphere.h"
  "${SRCROOT}${AERODYNAMICSDIR}/hypersonicLocalInclinationAnalysis.h"
  "${SRCROOT}${AERODYNAMICSDIR}/tabulatedAtmosphere.h"
  "${SRCROOT}${AERODYNAMICSDIR}/standardAtmosphere.h"
)

# Add static libraries.
add_library(tudat_aerodynamics STATIC ${AERODYNAMICS_SOURCES} ${AERODYNAMICS_HEADERS})
setup_tudat_library_target(tudat_aerodynamics "${SRCROOT}{AERODYNAMICSDIR}")

# Add unit tests.
add_executable(test_AerodynamicMomentAndAerodynamicForce "${SRCROOT}${AERODYNAMICSDIR}/UnitTests/unitTestAerodynamicMomentAndAerodynamicForce.cpp")
setup_custom_test_program(test_AerodynamicMomentAndAerodynamicForce "${SRCROOT}${AERODYNAMICSDIR}")
target_link_libraries(test_AerodynamicMomentAndAerodynamicForce tudat_aerodynamics ${Boost_LIBRARIES})

add_executable(test_AerodynamicsNamespace "${SRCROOT}${AERODYNAMICSDIR}/UnitTests/unitTestAerodynamicsNamespace.cpp")
setup_custom_test_program(test_AerodynamicsNamespace "${SRCROOT}${AERODYNAMICSDIR}")
target_link_libraries(test_AerodynamicsNamespace tudat_aerodynamics ${TUDAT_CORE_LIBRARIES} ${Boost_LIBRARIES})

add_executable(test_CoefficientGenerator "${SRCROOT}${AERODYNAMICSDIR}/UnitTests/unitTestCoefficientGenerator.cpp")
setup_custom_test_program(test_CoefficientGenerator "${SRCROOT}${AERODYNAMICSDIR}")
target_link_libraries(test_CoefficientGenerator tudat_aerodynamics tudat_geometric_shapes tudat_basic_mathematics ${TUDAT_CORE_LIBRARIES} ${Boost_LIBRARIES})

add_executable(test_ExponentialAtmosphere "${SRCROOT}${AERODYNAMICSDIR}/UnitTests/unitTestExponentialAtmosphere.cpp")
setup_custom_test_program(test_ExponentialAtmosphere "${SRCROOT}${AERODYNAMICSDIR}")
target_link_libraries(test_ExponentialAtmosphere tudat_aerodynamics ${TUDAT_CORE_LIBRARIES} ${Boost_LIBRARIES})

add_executable(test_TabulatedAtmosphere "${SRCROOT}${AERODYNAMICSDIR}/UnitTests/unitTestTabulatedAtmosphere.cpp")
setup_custom_test_program(test_TabulatedAtmosphere "${SRCROOT}${AERODYNAMICSDIR}")
target_link_libraries(test_TabulatedAtmosphere tudat_aerodynamics tudat_interpolators tudat_basic_mathematics tudat_input_output ${TUDAT_CORE_LIBRARIES} ${Boost_LIBRARIES})
