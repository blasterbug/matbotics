/**
 * @file
 *
 * @section desc File description
 *
 * Control Matrix Robotics System Motor & Servo controller with an Arduino board
 *
 * @section copyright Copyright
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * @date 2015/04/20
 * @author Benjamin Sientzoff
 * @version 0.1
 */

#ifndef _MATBOTICS_CPP_
#define _MATBOTICS_CPP_

// use TWI/I2C to communicate with Controller
#include <Wire.h>

#include "Matbotics.h"

MTController::MTController() :
__servos_state( 0 ),
__battery_level( -1 )
{
    Wire.begin();
}

int MTController::batteryLevel()
{
    Wire.begin( CONTROLLER_ADDRESS );
    Wire.write( CTRL_BATT_LEVEL);
    Wire.endTransmission();
    return __battery_level;
}

void MTController::enableServos()
{
    __servos_state = 0xF;
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SERVO_ON );
    Wire.write( 0xF ); // enable all Servos
    Wire.endTransmission();
}

void MTController::servoOneSpeed( int servo_speed )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SRV1_SPEED );
    Wire.write( servo_speed );
    Wire.endTransmission();
}

void MTController::servoOneAngle( int angle )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SRV1_TRGT );
    Wire.write( angle );
    Wire.endTransmission();
}

void MTController::servoTwoSpeed( int servo_speed )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SRV2_SPEED );
    Wire.write( servo_speed );
    Wire.endTransmission();
}

void MTController::servoTwoAngle( int angle )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SRV2_TRGT );
    Wire.write( angle );
    Wire.endTransmission();
}

void MTController::servoThreeSpeed( int servo_speed )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SRV3_SPEED );
    Wire.write( servo_speed );
    Wire.endTransmission();
}

void MTController::servoThreeAngle( int angle )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SRV3_TRGT );
    Wire.write( angle );
    Wire.endTransmission();
}

void MTController::servoFourSpeed( int servo_speed )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SRV4_SPEED );
    Wire.write( servo_speed );
    Wire.endTransmission();
}

void MTController::servoFourAngle( int angle )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_SRV4_TRGT );
    Wire.write( angle );
    Wire.endTransmission();
}


void MTController::motorOneSpeed( int motor_speed )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_MTR1_SPEED );
    Wire.write( motor_speed );
    Wire.endTransmission();
}


int MTController::motorOnePosition()
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_MTR1_POS );
    Wire.endTransmission();
    return 0;
}

void MTController::motorOneReach( int target )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_MTR1_TRGT );
    Wire.write( target ) ;
    Wire.endTransmission();
}

void MTController::motorOneMode( MOTOR_MODES mode )
{
    Wire.beginTransmission( CONTROLLER_ADDRESS );
    Wire.write( CTRL_MTR1_MODE );
    Wire.write( mode ) ;
    Wire.endTransmission();
}

#endif // _MATBOTICS_CPP_