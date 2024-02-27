//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8SB1_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void
enter_DefaultMode_from_RESET (void)
{
  // $[Config Calls]
  // Save the SFRPAGE
  uint8_t SFRPAGE_save = SFRPAGE;
  PCA_0_enter_DefaultMode_from_RESET ();
  PCACH_2_enter_DefaultMode_from_RESET ();
  PORTS_0_enter_DefaultMode_from_RESET ();
  PORTS_1_enter_DefaultMode_from_RESET ();
  PBCFG_0_enter_DefaultMode_from_RESET ();
  CLOCK_0_enter_DefaultMode_from_RESET ();
  TIMER_SETUP_0_enter_DefaultMode_from_RESET ();
  IREF_0_enter_DefaultMode_from_RESET ();
  SMBUS_0_enter_DefaultMode_from_RESET ();
  INTERRUPT_0_enter_DefaultMode_from_RESET ();
  // Restore the SFRPAGE
  SFRPAGE = SFRPAGE_save;
  // [Config Calls]$

}

extern void
CLOCK_0_enter_DefaultMode_from_RESET (void)
{
  // $[CLKSEL - Clock Select]
  /***********************************************************************
   - SYSCLK is equal to selected clock source divided by 2
   - Clock derived from the Internal Low Power Oscillator
   ***********************************************************************/
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_2 | CLKSEL_CLKSL__LPOSC;
  // Wait for the clock to be ready
  while ((CLKSEL & CLKSEL_CLKRDY__BMASK) != CLKSEL_CLKRDY__SET)
    ;
  // [CLKSEL - Clock Select]$

}

extern void
IREF_0_enter_DefaultMode_from_RESET (void)
{
  // $[IREF0CN - Current Reference Control]
  /***********************************************************************
   - IREF0 is a current source
   - High Current Mode is selected 
   - IREF0 Data Word = 0x00
   ***********************************************************************/
  IREF0CN0 = IREF0CN0_SINK__DISABLED | IREF0CN0_MDSEL__HIGH_CURRENT
      | (0x00 << IREF0CN0_IREF0DAT__SHIFT);
  // [IREF0CN - Current Reference Control]$

  // $[IREF0CF - Current Reference Configuration]
  // [IREF0CF - Current Reference Configuration]$

}

extern void
PCA_0_enter_DefaultMode_from_RESET (void)
{
  // $[PCA0MD - PCA Mode]
  /***********************************************************************
   - Disable Watchdog Timer
   - System clock divided by 12
   - PCA continues to function normally while the system controller is in
   Idle Mode
   - Disable the CF interrupt
   - Disable Watchdog Timer
   - Watchdog Timer Enable unlocked
   ***********************************************************************/
  SFRPAGE = 0x00;
  PCA0MD &= ~PCA0MD_WDTE__BMASK;
  PCA0MD = PCA0MD_CPS__SYSCLK_DIV_12 | PCA0MD_CIDL__NORMAL
      | PCA0MD_ECF__OVF_INT_DISABLED | PCA0MD_WDTE__DISABLED
      | PCA0MD_WDLCK__UNLOCKED;
  // [PCA0MD - PCA Mode]$

  // $[PCA0H - PCA Counter/Timer High Byte]
  // [PCA0H - PCA Counter/Timer High Byte]$

  // $[PCA0L - PCA Counter/Timer Low Byte]
  // [PCA0L - PCA Counter/Timer Low Byte]$

  // $[PCA0PWM - PCA PWM Configuration]
  // [PCA0PWM - PCA PWM Configuration]$

  // $[PCA0CN0 - PCA Control 0]
  // [PCA0CN0 - PCA Control 0]$

}

extern void
PCACH_2_enter_DefaultMode_from_RESET (void)
{
  // $[PCA0 Settings Save]
  // Select Capture/Compare register)
  PCA0PWM &= ~PCA0PWM_ARSEL__BMASK;
  // [PCA0 Settings Save]$

  // $[PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]
  /***********************************************************************
   - Disable negative edge capture
   - Disable CCF2 interrupts
   - Enable match function
   - 8 to 11-bit PWM selected
   - Disable positive edge capture
   - Disable comparator function
   - Disable PWM function
   - Disable toggle function
   ***********************************************************************/
  PCA0CPM2 = PCA0CPM2_CAPN__DISABLED | PCA0CPM2_ECCF__DISABLED
      | PCA0CPM2_MAT__ENABLED | PCA0CPM2_PWM16__8_BIT | PCA0CPM2_CAPP__DISABLED
      | PCA0CPM2_ECOM__DISABLED | PCA0CPM2_PWM__DISABLED
      | PCA0CPM2_TOG__DISABLED;
  // [PCA0CPM2 - PCA Channel 2 Capture/Compare Mode]$

  // $[PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]
  // [PCA0CPL2 - PCA Channel 2 Capture Module Low Byte]$

  // $[PCA0CPH2 - PCA Channel 2 Capture Module High Byte]
  PCA0CPH2 = 0x00;
  // [PCA0CPH2 - PCA Channel 2 Capture Module High Byte]$

  // $[Auto-reload]
  // [Auto-reload]$

  // $[PCA0 Settings Restore]
  // [PCA0 Settings Restore]$

}

extern void
SMBUS_0_enter_DefaultMode_from_RESET (void)
{
  // $[SMB0ADR - SMBus 0 Slave Address]
  // [SMB0ADR - SMBus 0 Slave Address]$

  // $[SMB0ADM - SMBus 0 Slave Address Mask]
  // [SMB0ADM - SMBus 0 Slave Address Mask]$

  // $[SMB0CF - SMBus 0 Configuration]
  /***********************************************************************
   - Timer 1 Overflow
   - Enable the SMBus module
   ***********************************************************************/
  SMB0CF &= ~SMB0CF_SMBCS__FMASK;
  SMB0CF |= SMB0CF_SMBCS__TIMER1 | SMB0CF_ENSMB__ENABLED;
  // [SMB0CF - SMBus 0 Configuration]$

}

extern void
INTERRUPT_0_enter_DefaultMode_from_RESET (void)
{
  // $[EIE1 - Extended Interrupt Enable 1]
  /***********************************************************************
   - Disable ADC0 Conversion Complete interrupt
   - Disable ADC0 Window Comparison interrupt
   - Disable CP0 interrupts
   - Disable all PCA0 interrupts
   - Disable RTC Alarm interrupts
   - Enable interrupt requests generated by SMB0
   - Disable Timer 3 interrupts
   ***********************************************************************/
  EIE1 = EIE1_EADC0__DISABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
      | EIE1_EPCA0__DISABLED | EIE1_ERTC0A__DISABLED | EIE1_ESMB0__ENABLED
      | EIE1_ET3__DISABLED;
  // [EIE1 - Extended Interrupt Enable 1]$

  // $[EIP1 - Extended Interrupt Priority 1]
  // [EIP1 - Extended Interrupt Priority 1]$

  // $[IE - Interrupt Enable]
  /***********************************************************************
   - Enable each interrupt according to its individual mask setting
   - Disable external interrupt 0
   - Disable external interrupt 1
   - Disable all SPI0 interrupts
   - Disable all Timer 0 interrupt
   - Disable all Timer 1 interrupt
   - Enable interrupt requests generated by the TF2L or TF2H flags
   - Disable UART0 interrupt
   ***********************************************************************/
  IE = IE_EA__ENABLED | IE_EX0__DISABLED | IE_EX1__DISABLED | IE_ESPI0__DISABLED
      | IE_ET0__DISABLED | IE_ET1__DISABLED | IE_ET2__ENABLED
      | IE_ES0__DISABLED;
  // [IE - Interrupt Enable]$

  // $[IP - Interrupt Priority]
  // [IP - Interrupt Priority]$

  // $[EIE2 - Extended Interrupt Enable 2]
  // [EIE2 - Extended Interrupt Enable 2]$

  // $[EIP2 - Extended Interrupt Priority 2]
  // [EIP2 - Extended Interrupt Priority 2]$

}

extern void
TIMER_SETUP_0_enter_DefaultMode_from_RESET (void)
{
  // $[CKCON0 - Clock Control 0]
  /***********************************************************************
   - System clock divided by 12
   - Counter/Timer 0 uses the clock defined by the prescale field, SCA
   - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
   - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
   - Timer 1 uses the system clock
   ***********************************************************************/
  CKCON0 = CKCON0_SCA__SYSCLK_DIV_12 | CKCON0_T0M__PRESCALE
      | CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
      | CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
      | CKCON0_T1M__SYSCLK;
  // [CKCON0 - Clock Control 0]$

  // $[TMOD - Timer 0/1 Mode]
  /***********************************************************************
   - Mode 0, 13-bit Counter/Timer
   - Mode 2, 8-bit Counter/Timer with Auto-Reload
   - Timer Mode
   - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
   - Timer Mode
   - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
   ***********************************************************************/
  TMOD = TMOD_T0M__MODE0 | TMOD_T1M__MODE2 | TMOD_CT0__TIMER
      | TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
  // [TMOD - Timer 0/1 Mode]$

  // $[TCON - Timer 0/1 Control]
  /***********************************************************************
   - Start Timer 1 running
   ***********************************************************************/
  TCON |= TCON_TR1__RUN;
  // [TCON - Timer 0/1 Control]$

}

extern void
PORTS_0_enter_DefaultMode_from_RESET (void)
{
  // $[P0 - Port 0 Pin Latch]
  // [P0 - Port 0 Pin Latch]$

  // $[P0MDOUT - Port 0 Output Mode]
  /***********************************************************************
   - P0.0 output is open-drain
   - P0.1 output is open-drain
   - P0.2 output is push-pull
   - P0.3 output is push-pull
   - P0.4 output is push-pull
   - P0.5 output is push-pull
   - P0.6 output is open-drain
   - P0.7 output is open-drain
   ***********************************************************************/
  P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__OPEN_DRAIN
      | P0MDOUT_B2__PUSH_PULL | P0MDOUT_B3__PUSH_PULL | P0MDOUT_B4__PUSH_PULL
      | P0MDOUT_B5__PUSH_PULL | P0MDOUT_B6__OPEN_DRAIN | P0MDOUT_B7__OPEN_DRAIN;
  // [P0MDOUT - Port 0 Output Mode]$

  // $[P0MDIN - Port 0 Input Mode]
  /***********************************************************************
   - P0.0 pin is configured for digital mode
   - P0.1 pin is configured for digital mode
   - P0.2 pin is configured for digital mode
   - P0.3 pin is configured for digital mode
   - P0.4 pin is configured for digital mode
   - P0.5 pin is configured for digital mode
   - P0.6 pin is configured for analog mode
   - P0.7 pin is configured for analog mode
   ***********************************************************************/
  P0MDIN = P0MDIN_B0__DIGITAL | P0MDIN_B1__DIGITAL | P0MDIN_B2__DIGITAL
      | P0MDIN_B3__DIGITAL | P0MDIN_B4__DIGITAL | P0MDIN_B5__DIGITAL
      | P0MDIN_B6__ANALOG | P0MDIN_B7__ANALOG;
  // [P0MDIN - Port 0 Input Mode]$

  // $[P0SKIP - Port 0 Skip]
  /***********************************************************************
   - P0.0 pin is not skipped by the crossbar
   - P0.1 pin is not skipped by the crossbar
   - P0.2 pin is skipped by the crossbar
   - P0.3 pin is skipped by the crossbar
   - P0.4 pin is skipped by the crossbar
   - P0.5 pin is skipped by the crossbar
   - P0.6 pin is skipped by the crossbar
   - P0.7 pin is skipped by the crossbar
   ***********************************************************************/
  P0SKIP = P0SKIP_B0__NOT_SKIPPED | P0SKIP_B1__NOT_SKIPPED | P0SKIP_B2__SKIPPED
      | P0SKIP_B3__SKIPPED | P0SKIP_B4__SKIPPED | P0SKIP_B5__SKIPPED
      | P0SKIP_B6__SKIPPED | P0SKIP_B7__SKIPPED;
  // [P0SKIP - Port 0 Skip]$

  // $[P0MASK - Port 0 Mask]
  // [P0MASK - Port 0 Mask]$

  // $[P0MAT - Port 0 Match]
  // [P0MAT - Port 0 Match]$

  // $[P0DRV - Port 0 Drive Strength]
  // [P0DRV - Port 0 Drive Strength]$

}

extern void
PORTS_1_enter_DefaultMode_from_RESET (void)
{
  // $[P1 - Port 1 Pin Latch]
  // [P1 - Port 1 Pin Latch]$

  // $[P1MDOUT - Port 1 Output Mode]
  /***********************************************************************
   - P1.0 output is open-drain
   - P1.1 output is push-pull
   - P1.2 output is open-drain
   - P1.3 output is open-drain
   - P1.4 output is push-pull
   - P1.5 output is push-pull
   - P1.6 output is push-pull
   - P1.7 output is push-pull
   ***********************************************************************/
  P1MDOUT = P1MDOUT_B0__OPEN_DRAIN | P1MDOUT_B1__PUSH_PULL
      | P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__OPEN_DRAIN | P1MDOUT_B4__PUSH_PULL
      | P1MDOUT_B5__PUSH_PULL | P1MDOUT_B6__PUSH_PULL | P1MDOUT_B7__PUSH_PULL;
  // [P1MDOUT - Port 1 Output Mode]$

  // $[P1MDIN - Port 1 Input Mode]
  // [P1MDIN - Port 1 Input Mode]$

  // $[P1SKIP - Port 1 Skip]
  /***********************************************************************
   - P1.0 pin is skipped by the crossbar
   - P1.1 pin is not skipped by the crossbar
   - P1.2 pin is not skipped by the crossbar
   - P1.3 pin is not skipped by the crossbar
   - P1.4 pin is skipped by the crossbar
   - P1.5 pin is skipped by the crossbar
   - P1.6 pin is skipped by the crossbar
   - P1.7 pin is skipped by the crossbar
   ***********************************************************************/
  P1SKIP = P1SKIP_B0__SKIPPED | P1SKIP_B1__NOT_SKIPPED | P1SKIP_B2__NOT_SKIPPED
      | P1SKIP_B3__NOT_SKIPPED | P1SKIP_B4__SKIPPED | P1SKIP_B5__SKIPPED
      | P1SKIP_B6__SKIPPED | P1SKIP_B7__SKIPPED;
  // [P1SKIP - Port 1 Skip]$

  // $[Missing Pin Skip]
  // [Missing Pin Skip]$

  // $[P1MASK - Port 1 Mask]
  // [P1MASK - Port 1 Mask]$

  // $[P1MAT - Port 1 Match]
  // [P1MAT - Port 1 Match]$

  // $[P1DRV - Port 1 Drive Strength]
  // [P1DRV - Port 1 Drive Strength]$

}

extern void
PBCFG_0_enter_DefaultMode_from_RESET (void)
{
  // $[XBR2 - Port I/O Crossbar 2]
  // [XBR2 - Port I/O Crossbar 2]$

  // $[XBR0 - Port I/O Crossbar 0]
  /***********************************************************************
   - UART I/O unavailable at Port pin
   - SPI I/O unavailable at Port pins
   - SMBus 0 I/O routed to Port pins
   - CP0 unavailable at Port pin
   - Asynchronous CP0 unavailable at Port pin
   - SYSCLK unavailable at Port pin
   ***********************************************************************/
  XBR0 = XBR0_URT0E__DISABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__ENABLED
      | XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED | XBR0_SYSCKE__DISABLED;
  // [XBR0 - Port I/O Crossbar 0]$

  // $[XBR1 - Port I/O Crossbar 1]
  // [XBR1 - Port I/O Crossbar 1]$

}
