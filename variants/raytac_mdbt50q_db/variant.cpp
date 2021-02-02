/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.
  Copyright (c) 2016 Sandeep Mistry All right reserved.
  Copyright (c) 2018, Adafruit Industries (adafruit.com)

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

#define _PINNUM(port, pin)     ((port)*32 + (pin))

const uint32_t g_ADigitalPinMap[] =
{
  _PINNUM(1, 11),	// D0 on P1.11		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 13),	// D1 on P1.13		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 15),	// D2 on P1.15		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 29),	// D3 on P0.29	 is A0	**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 31),	// D4 on P0.31	 is A1	**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 30),	// D5 on P0.30	 is A2	**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 6),	// D6 on P1.6		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 7),	// D7 on P1.7		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 4),	// D8 on P0.4	 is A3	
  _PINNUM(0, 6),	// D9 on P0.6	 is TX	
  _PINNUM(0, 8),	// D10 on P0.8	 is RX	
  _PINNUM(1, 10),	// D11 on P1.10		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 12),	// D12 on P1.12		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 14),	// D13 on P1.14		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 3),	// D14 on P0.3	 is A4	**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 2),	// D15 on P0.2	 is A5	**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 28),	// D16 on P0.28	 is A6	**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 4),	// D17 on P1.4		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 27),	// D18 on P0.27	 is SPI MISO	
  _PINNUM(0, 26),	// D19 on P0.26	 is SPI MOSI	
  _PINNUM(0, 5),	// D20 on P0.5	 is A7,RTS	
  _PINNUM(0, 7),	// D21 on P0.7	 is CTS	
  _PINNUM(1, 8),	// D22 on P1.8	 is SPI SCK	
  _PINNUM(0, 10),	// D23 on P0.10	 is NFC2	**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 2),	// D24 on P1.2		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 24),	// D25 on P0.24	 is SW3	
  _PINNUM(0, 22),	// D26 on P0.22	 is QSPI DATA 2	
  _PINNUM(0, 20),	// D27 on P0.20	 is QSPI CS	
  _PINNUM(0, 19),	// D28 on P0.19	 is QSPI CLK	
  _PINNUM(0, 18),	// D29 on P0.18		
  _PINNUM(0, 16),	// D30 on P0.16	 is LED D4	
  _PINNUM(0, 14),	// D31 on P0.14	 is LED D2	
  _PINNUM(1, 3),	// D32 on P1.3		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 12),	// D33 on P0.12	 is SW2	
  _PINNUM(1, 9),	// D34 on P1.9	 is SCL	
  _PINNUM(0, 9),	// D35 on P0.9	 is NFC1	**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 25),	// D36 on P0.25	 is SW4	
  _PINNUM(1, 0),	// D37 on P1.0	 is SDA	
  _PINNUM(0, 23),	// D38 on P0.23	 is QSPI DATA 1	
  _PINNUM(0, 21),	// D39 on P0.21	 is QSPI DATA 3	
  _PINNUM(0, 17),	// D40 on P0.17	 is QSPI DATA 0	
  _PINNUM(0, 15),	// D41 on P0.15	 is LED D3	
  _PINNUM(0, 13),	// D42 on P0.13	 is LED D1	
  _PINNUM(1, 1),	// D43 on P1.1		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(1, 5),	// D44 on P1.5		**LOW-FREQUENCY (<10kHz) ONLY**
  _PINNUM(0, 11),	// D45 on P0.11	 is SW1	
  _PINNUM(0, 0),	// D46 on P0.0	 is 32.768KHZ XTL	
  _PINNUM(0, 1),	// D47 on P0.1	 is 32.768KHZ XTL	
};



void initVariant()
{
  // LED1 & LED2
  pinMode(PIN_LED1, OUTPUT);
  ledOff(PIN_LED1);

  pinMode(PIN_LED2, OUTPUT);
  ledOff(PIN_LED2);
}

