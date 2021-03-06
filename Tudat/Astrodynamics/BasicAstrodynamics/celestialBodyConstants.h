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
 *      121011    M. Ganeff         Code created.
 *      130319    K. Kumar          Split off code and created file for common celestial body
 *                                  constants.
 *
 *    References
 *      International Earth Rotation and Reference System Service, Conventions 2010 (IERS2010),
 *        http://www.iers.org/IERS/EN/Publications/TechnicalNotes/tn36.html
 *      JPL, NASA. Astrodynamic Constants, http://ssd.jpl.nasa.gov/?constants,
 *        last updated: 13 Dec, 2012, last accessed: 19th March, 2013.
 *      JPL, NASA. Introduction to SPICE, 
 *        http://naif.jpl.nasa.gov/pub/naif/toolkit_docs/C/info/intrdctn.html, last updated:
 *        29th Feb, 2008, last accessed: 22nd March, 2012.   		
 *      EGM 2008 gravity field model, http://earth-info.nga.mil/GandG/wgs84/gravitymod/egm2008/
 *        last accessed: 21 March, 2013.
 *
 *    Notes
 *      All the gravitational constants given here are taken from NASA JPL's list of astrodynamic
 *      constants (JPL, 2012), except for the Earth (IERS, 2010).
 *
 *      The data in this file is not meant to be used for precise orbit applications, such as
 *      orbit determination or Earth-orbiting mission operations analysis. For such applications
 *      specific, up-to-date constants, should be retrieved from, for instance the IERS or IAU.
 *      The Spice libraries provide a range of additional constants too (JPL, 2008).
 *
 */

#ifndef TUDAT_CELESTIAL_BODY_CONSTANTS_H
#define TUDAT_CELESTIAL_BODY_CONSTANTS_H

namespace tudat
{
namespace basic_astrodynamics
{
namespace celestial_body_constants
{

//! Earth equatorial radius.
/*!
 * Earth equatorial radius in meters [m] (IERS, 2010).
 */
const static double EARTH_EQUATORIAL_RADIUS = 6378136.6;

//! Earth flattening factor.
/*!
 * Earth flattening factor [-] (IERS, 2010).
 */
const static double EARTH_FLATTENING_FACTOR = 298.25642;

//! Earth spherical harmonic gravitational field J2
/*!
 * Earth spherical harmonic gravitational field J2 [-] (EGM2008, 2013)
 */
const static double EARTH_GEODESY_NORMALIZED_J2 = -0.484165143790815E-03;

//! Solar gravitational constant.
/*!
 * Solar gravitational constant in squared meters per second squared [m^3 s^-2] (JPL, 2012).
 */
const static double SUN_GRAVITATIONAL_PARAMETER = 1.32712440018e20;

//! Mercury gravitational constant.
/*!
 * Gravitational constant of Mercury, derived from Sun/Mercury mass ratio [m^3 s^-2] (JPL, 2012).
 */
const static double MERCURY_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER / 6023600.0;

//! Venus gravitational constant.
/*!
 * Gravitational constant of Venus, derived from Sun/Venus mass ratio [m^3 s^-2] (JPL, 2012).
 */
const static double VENUS_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER / 408523.71;

//! Earth gravitational constant.
/*!
 * Earth gravitational constant in squared meters per second squared [m^3 s^-2] (IERS, 2012).
 */
const static double EARTH_GRAVITATIONAL_PARAMETER = 3.986004418E14;

//! Moon gravitational constant.
/*!
 * Moon gravitational constant in squared meters per second squared [m^3 s^-2] (JPL, 2012).
 */
const static double MOON_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER /
        ( 328900.56 * ( 1.0 + 81.30059 ) );

//! Mars gravitational constant.
/*!
 * Gravitational constant of Mars, derived from Sun/Mars mass ratio [m^3 s^-2] (JPL, 2012).
 */
const static double MARS_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER / 3098708.0;

//! Jupiter gravitational constant.
/*!
 * Gravitational constant of Jupiter, derived from Sun/Jupiter mass ratio [m^3 s^-2] (JPL, 2012).
 */
const static double JUPITER_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER / 1047.3486;

//! Saturn gravitational constant.
/*!
 * Gravitational constant of Saturn, derived from Sun/Saturn mass ratio [m^3 s^-2] (JPL, 2012).
 */
const static double SATURN_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER / 3497.898 ;

//! Uranus gravitational constant.
/*!
 * Gravitational constant of Uranus, derived from Sun/Uranus mass ratio [m^3 s^-2] (JPL, 2012).
 */
const static double URANUS_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER / 22902.98;

//! Neptune gravitational constant.
/*!
 * Gravitational constant of Neptune, derived from Sun/Neptune mass ratio [m^3 s^-2] (JPL, 2012).
 */
const static double NEPTUNE_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER / 19412.24;

//! Pluto gravitational constant.
/*!
 * Gravitational constant of Pluto, derived from Sun/Pluto mass ratio [m^3 s^-2] (JPL, 2012).
 */
const static double PLUTO_GRAVITATIONAL_PARAMETER = SUN_GRAVITATIONAL_PARAMETER / 1.35e8;

} // namespace celestial_body_constants
} // namespace basic_astrodynamics
} // namespace tudat

#endif // TUDAT_CELESTIAL_BODY_CONSTANTS_H
