/*
 * File:   newmainXC16.c
 * Author: George Main IV
 *
 * This project will turn on an LED when a button is pressed
 * 
 * Created on June 3, 2017, 10:32 AM
 */


// DSPIC33EV256GM102 Configuration Bit Settings

// 'C' source line config statements

// FSEC
#pragma config BWRP = OFF               // Boot Segment Write-Protect Bit (Boot Segment may be written)
#pragma config BSS = DISABLED           // Boot Segment Code-Protect Level bits (No Protection (other than BWRP))
#pragma config BSS2 = OFF               // Boot Segment Control Bit (No Boot Segment)
#pragma config GWRP = OFF               // General Segment Write-Protect Bit (General Segment may be written)
#pragma config GSS = DISABLED           // General Segment Code-Protect Level bits (No Protection (other than GWRP))
#pragma config CWRP = OFF               // Configuration Segment Write-Protect Bit (Configuration Segment may be written)
#pragma config CSS = DISABLED           // Configuration Segment Code-Protect Level bits (No Protection (other than CWRP))
#pragma config AIVTDIS = DISABLE        // Alternate Interrupt Vector Table Disable Bit  (Disable Alternate Vector Table)

// FBSLIM
#pragma config BSLIM = 0x1FFF           // Boot Segment Code Flash Page Address Limit Bits (Boot Segment Flash Page Address Limit (0-0x1FFF))

// FOSCSEL
#pragma config FNOSC = FRCDIVN          // Initial oscillator Source Selection Bits (Internal Fast RC (FRC) Oscillator with postscaler)
#pragma config IESO = ON                // Two Speed Oscillator Start-Up Bit (Start up device with FRC,then automatically switch to user selected oscillator source)

// FOSC
#pragma config POSCMD = HS              // Primary Oscillator Mode Select Bits (HS Crystal Oscillator mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin I/O Function Enable Bit (OSC2 is clock output)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration Bit (Allow Only One reconfiguration)
#pragma config FCKSM = CSDCMD           // Clock Switching Mode Bits (Both Clock Switching and Fail-safe Clock Monitor are disabled)
#pragma config PLLKEN = ON              // PLL Lock Enable Bit (Clock switch to PLL source will wait until the PLL lock signal is valid)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler Bits (1:32,768)
#pragma config WDTPRE = PR128           // Watchdog Timer Prescaler Bit (1:128)
#pragma config FWDTEN = OFF              // Watchdog Timer Enable Bits (WDT Enabled)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable Bit (Watchdog timer in Non-Window Mode)
#pragma config WDTWIN = WIN25           // Watchdog Window Select Bits (WDT Window is 25% of WDT period)

// FPOR
#pragma config BOREN0 = ON              // Brown Out Reset Detection Bit (BOR is Enabled)

// FICD
#pragma config ICS = PGD1               // ICD Communication Channel Select Bits (Communicate on PGEC1 and PGED1)

// FDMTINTVL
#pragma config DMTIVTL = 0xFFFF         // Lower 16 Bits of 32 Bit DMT Window Interval (Lower 16 bits of 32 bit DMT window interval (0-0xFFFF))

// FDMTINTVH
#pragma config DMTIVTH = 0xFFFF         // Upper 16 Bits of 32 Bit DMT Window Interval (Upper 16 bits of 32 bit DMT window interval (0-0xFFFF))

// FDMTCNTL
#pragma config DMTCNTL = 0xFFFF         // Lower 16 Bits of 32 Bit DMT Instruction Count Time-Out Value (Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF))

// FDMTCNTH
#pragma config DMTCNTH = 0xFFFF         // Upper 16 Bits of 32 Bit DMT Instruction Count Time-Out Value (Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF))

// FDMT
#pragma config DMTEN = ENABLE           // Dead Man Timer Enable Bit (Dead Man Timer is Enabled and cannot be disabled by software)

// FDEVOPT
#pragma config PWMLOCK = ON             // PWM Lock Enable Bit (Certain PWM registers may only be written after key sequence)
#pragma config ALTI2C1 = OFF            // Alternate I2C1 Pins Selection Bit (I2C1 mapped to SDA1/SCL1 pins)

// FALTREG
#pragma config CTXT1 = NONE             // Interrupt Priority Level (IPL) Selection Bits For Alternate Working Register Set 1 (Not Assigned)
#pragma config CTXT2 = NONE             // Interrupt Priority Level (IPL) Selection Bits For Alternate Working Register Set 2 (Not Assigned)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <libpic30.h>
#include <p33ev256gm102.h>


int main(void) {
    
    device_initialize();
    
    // Set TRIS, PORT, and ANSEL B to zeros
    ANSELB = 0x0;
    TRISB = 0x0;
    PORTB = 0x0;

    // Set RB6 as INPUT pin
    TRISBbits.TRISB6 = 1;
    
    // Main Loop
    while (1) {
 
        // Check if the button was pressed, if so turn on the LED
        if (PORTBbits.RB6 == 0) {
            PORTBbits.RB7 = 1;
        } else {
            PORTBbits.RB7 = 0;
        }
    }   
}
