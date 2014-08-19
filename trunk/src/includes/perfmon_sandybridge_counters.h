/*
 * =======================================================================================
 *
 *      Filename:  perfmon_sandybridge_counters.h
 *
 *      Description: Counter header file of perfmon module for Sandy Bridge.
 *
 *      Version:   <VERSION>
 *      Released:  <DATE>
 *
 *      Author:  Jan Treibig (jt), jan.treibig@gmail.com
 *      Project:  likwid
 *
 *      Copyright (C) 2013 Jan Treibig 
 *
 *      This program is free software: you can redistribute it and/or modify it under
 *      the terms of the GNU General Public License as published by the Free Software
 *      Foundation, either version 3 of the License, or (at your option) any later
 *      version.
 *
 *      This program is distributed in the hope that it will be useful, but WITHOUT ANY
 *      WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 *      PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along with
 *      this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * =======================================================================================
 */

#define NUM_COUNTERS_SANDYBRIDGE 82
#define NUM_COUNTERS_UNCORE_SANDYBRIDGE 74
#define NUM_COUNTERS_CORE_SANDYBRIDGE 8

#define OFFSET_PMC 3

#define VALID_OPTIONS_FIXED EVENT_OPTION_COUNT_KERNEL_MASK
#define VALID_OPTIONS_PMC EVENT_OPTION_EDGE_MASK|EVENT_OPTION_COUNT_KERNEL_MASK
#define VALID_OPTIONS_THERMAL EVENT_OPTION_NONE_MASK
#define VALID_OPTIONS_POWER EVENT_OPTION_NONE_MASK
#define VALID_OPTIONS_CBOX EVENT_OPTION_THRESHOLD_MASK|EVENT_OPTION_EDGE_MASK|EVENT_OPTION_TID_MASK
#define VALID_OPTIONS_UBOX EVENT_OPTION_NONE_MASK
#define VALID_OPTIONS_BBOX EVENT_OPTION_NONE_MASK
#define VALID_OPTIONS_MBOX EVENT_OPTION_NONE_MASK
#define VALID_OPTIONS_SBOX EVENT_OPTION_NONE_MASK
#define VALID_OPTIONS_WBOX  EVENT_OPTION_EDGE_MASK|EVENT_OPTION_INVERT_MASK|EVENT_OPTION_THRESHOLD_MASK| \
                            EVENT_OPTION_OCCUPANCY_MASK|EVENT_OPTION_OCCUPANCY_EDGE_MASK| \
                            EVENT_OPTION_OCCUPANCY_INVERT_MASK


static RegisterMap sandybridge_counter_map[NUM_COUNTERS_SANDYBRIDGE] = {
    /* Fixed Counters: instructions retired, cycles unhalted core */
    {"FIXC0", PMC0, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR0, 0, 0, VALID_OPTIONS_FIXED},
    {"FIXC1", PMC1, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR1, 0, 0, VALID_OPTIONS_FIXED},
    {"FIXC2", PMC2, FIXED, MSR_PERF_FIXED_CTR_CTRL, MSR_PERF_FIXED_CTR2, 0, 0, VALID_OPTIONS_FIXED},
    /* PMC Counters: 4 48bit wide */
    {"PMC0", PMC3, PMC, MSR_PERFEVTSEL0, MSR_PMC0, 0, 0, VALID_OPTIONS_PMC},
    {"PMC1", PMC4, PMC, MSR_PERFEVTSEL1, MSR_PMC1, 0, 0, VALID_OPTIONS_PMC},
    {"PMC2", PMC5, PMC, MSR_PERFEVTSEL2, MSR_PMC2, 0, 0, VALID_OPTIONS_PMC},
    {"PMC3", PMC6, PMC, MSR_PERFEVTSEL3, MSR_PMC3, 0, 0, VALID_OPTIONS_PMC},
    /* Temperature Sensor*/
    {"TMP0", PMC7, THERMAL, 0, 0, 0, 0, VALID_OPTIONS_THERMAL},
    /* RAPL counters */
    {"PWR0", PMC8, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, VALID_OPTIONS_POWER},
    {"PWR1", PMC9, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, VALID_OPTIONS_POWER},
    {"PWR2", PMC10, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, VALID_OPTIONS_POWER},
    {"PWR3", PMC11, POWER, 0, MSR_PKG_ENERGY_STATUS, 0, 0, VALID_OPTIONS_POWER},
    /* CBOX counters */
    {"CBOX0C0", PMC12, CBOX0, MSR_UNC_C0_PMON_CTL0, MSR_UNC_C0_PMON_CTR0, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX0C1", PMC13, CBOX0, MSR_UNC_C0_PMON_CTL1, MSR_UNC_C0_PMON_CTR1, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX0C2", PMC14, CBOX0, MSR_UNC_C0_PMON_CTL2, MSR_UNC_C0_PMON_CTR2, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX0C3", PMC15, CBOX0, MSR_UNC_C0_PMON_CTL3, MSR_UNC_C0_PMON_CTR3, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX1C0", PMC16, CBOX1, MSR_UNC_C1_PMON_CTL0, MSR_UNC_C1_PMON_CTR0, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX1C1", PMC17, CBOX1, MSR_UNC_C1_PMON_CTL1, MSR_UNC_C1_PMON_CTR1, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX1C2", PMC18, CBOX1, MSR_UNC_C1_PMON_CTL2, MSR_UNC_C1_PMON_CTR2, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX1C3", PMC19, CBOX1, MSR_UNC_C1_PMON_CTL3, MSR_UNC_C1_PMON_CTR3, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX2C0", PMC20, CBOX2, MSR_UNC_C2_PMON_CTL0, MSR_UNC_C2_PMON_CTR0, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX2C1", PMC21, CBOX2, MSR_UNC_C2_PMON_CTL1, MSR_UNC_C2_PMON_CTR1, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX2C2", PMC22, CBOX2, MSR_UNC_C2_PMON_CTL2, MSR_UNC_C2_PMON_CTR2, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX2C3", PMC23, CBOX2, MSR_UNC_C2_PMON_CTL3, MSR_UNC_C2_PMON_CTR3, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX3C0", PMC24, CBOX3, MSR_UNC_C3_PMON_CTL0, MSR_UNC_C3_PMON_CTR0, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX3C1", PMC25, CBOX3, MSR_UNC_C3_PMON_CTL1, MSR_UNC_C3_PMON_CTR1, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX3C2", PMC26, CBOX3, MSR_UNC_C3_PMON_CTL2, MSR_UNC_C3_PMON_CTR2, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX3C3", PMC27, CBOX3, MSR_UNC_C3_PMON_CTL3, MSR_UNC_C3_PMON_CTR3, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX4C0", PMC28, CBOX4, MSR_UNC_C4_PMON_CTL0, MSR_UNC_C4_PMON_CTR0, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX4C1", PMC29, CBOX4, MSR_UNC_C4_PMON_CTL1, MSR_UNC_C4_PMON_CTR1, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX4C2", PMC30, CBOX4, MSR_UNC_C4_PMON_CTL2, MSR_UNC_C4_PMON_CTR2, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX4C3", PMC31, CBOX4, MSR_UNC_C4_PMON_CTL3, MSR_UNC_C4_PMON_CTR3, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX5C0", PMC32, CBOX5, MSR_UNC_C5_PMON_CTL0, MSR_UNC_C5_PMON_CTR0, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX5C1", PMC33, CBOX5, MSR_UNC_C5_PMON_CTL1, MSR_UNC_C5_PMON_CTR1, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX5C2", PMC34, CBOX5, MSR_UNC_C5_PMON_CTL2, MSR_UNC_C5_PMON_CTR2, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX5C3", PMC35, CBOX5, MSR_UNC_C5_PMON_CTL3, MSR_UNC_C5_PMON_CTR3, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX6C0", PMC36, CBOX6, MSR_UNC_C6_PMON_CTL0, MSR_UNC_C6_PMON_CTR0, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX6C1", PMC37, CBOX6, MSR_UNC_C6_PMON_CTL1, MSR_UNC_C6_PMON_CTR1, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX6C2", PMC38, CBOX6, MSR_UNC_C6_PMON_CTL2, MSR_UNC_C6_PMON_CTR2, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX6C3", PMC39, CBOX6, MSR_UNC_C6_PMON_CTL3, MSR_UNC_C6_PMON_CTR3, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX7C0", PMC40, CBOX7, MSR_UNC_C7_PMON_CTL0, MSR_UNC_C7_PMON_CTR0, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX7C1", PMC41, CBOX7, MSR_UNC_C7_PMON_CTL1, MSR_UNC_C7_PMON_CTR1, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX7C2", PMC42, CBOX7, MSR_UNC_C7_PMON_CTL2, MSR_UNC_C7_PMON_CTR2, 0, 0, VALID_OPTIONS_CBOX},
    {"CBOX7C3", PMC43, CBOX7, MSR_UNC_C7_PMON_CTL3, MSR_UNC_C7_PMON_CTR3, 0, 0, VALID_OPTIONS_CBOX},
    /* UBOX counters */
    {"UBOX0", PMC44, UBOX, MSR_UNC_U_PMON_CTL0, MSR_UNC_U_PMON_CTR0, 0, 0, VALID_OPTIONS_UBOX},
    {"UBOX1", PMC45, UBOX, MSR_UNC_U_PMON_CTL1, MSR_UNC_U_PMON_CTR0, 0, 0, VALID_OPTIONS_UBOX},
    {"UBOXFIX", PMC46, UBOXFIX, MSR_UNC_U_UCLK_FIXED_CTL, MSR_UNC_U_UCLK_FIXED_CTR, 0, 0, EVENT_OPTION_NONE_MASK},
    /* IMC Counters: 4 48bit wide per memory channel, split in two reads */
    {"MBOX0C0",PMC47, MBOX0, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_CH_0, VALID_OPTIONS_MBOX},
    {"MBOX0C1",PMC48, MBOX0, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_CH_0, VALID_OPTIONS_MBOX},
    {"MBOX0C2",PMC49, MBOX0, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_CH_0, VALID_OPTIONS_MBOX},
    {"MBOX0C3",PMC50, MBOX0, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_CH_0, VALID_OPTIONS_MBOX},
    {"MBOX0FIX", PMC51, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_CH_0, EVENT_OPTION_NONE_MASK},
    {"MBOX1C0",PMC52, MBOX1, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_CH_1, VALID_OPTIONS_MBOX},
    {"MBOX1C1",PMC53, MBOX1, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_CH_1, VALID_OPTIONS_MBOX},
    {"MBOX1C2",PMC54, MBOX1, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_CH_1, VALID_OPTIONS_MBOX},
    {"MBOX1C3",PMC55, MBOX1, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_CH_1, VALID_OPTIONS_MBOX},
    {"MBOX1FIX", PMC56, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_CH_1, EVENT_OPTION_NONE_MASK},
    {"MBOX2C0",PMC57, MBOX2, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_CH_2, VALID_OPTIONS_MBOX},
    {"MBOX2C1",PMC58, MBOX2, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_CH_2, VALID_OPTIONS_MBOX},
    {"MBOX2C2",PMC59, MBOX2, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_CH_2, VALID_OPTIONS_MBOX},
    {"MBOX2C3",PMC60, MBOX2, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_CH_2, VALID_OPTIONS_MBOX},
    {"MBOX2FIX", PMC61, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_CH_2, EVENT_OPTION_NONE_MASK},
    {"MBOX0C0",PMC62, MBOX3, PCI_UNC_MC_PMON_CTL_0, PCI_UNC_MC_PMON_CTR_0_A, PCI_UNC_MC_PMON_CTR_0_B, PCI_IMC_DEVICE_CH_3, VALID_OPTIONS_MBOX},
    {"MBOX1C1",PMC63, MBOX3, PCI_UNC_MC_PMON_CTL_1, PCI_UNC_MC_PMON_CTR_1_A, PCI_UNC_MC_PMON_CTR_1_B, PCI_IMC_DEVICE_CH_3, VALID_OPTIONS_MBOX},
    {"MBOX2C2",PMC64, MBOX3, PCI_UNC_MC_PMON_CTL_2, PCI_UNC_MC_PMON_CTR_2_A, PCI_UNC_MC_PMON_CTR_2_B, PCI_IMC_DEVICE_CH_3, VALID_OPTIONS_MBOX},
    {"MBOX3C3",PMC65, MBOX3, PCI_UNC_MC_PMON_CTL_3, PCI_UNC_MC_PMON_CTR_3_A, PCI_UNC_MC_PMON_CTR_3_B, PCI_IMC_DEVICE_CH_3, VALID_OPTIONS_MBOX},
    {"MBOX3FIX", PMC66, MBOX0FIX, PCI_UNC_MC_PMON_FIXED_CTL, PCI_UNC_MC_PMON_FIXED_CTR_A, PCI_UNC_MC_PMON_FIXED_CTR_B, PCI_IMC_DEVICE_CH_3, EVENT_OPTION_NONE_MASK},
    /* QPI counters four 48bit  wide per port, split in two reads */
    {"SBOX0C0",PMC67, SBOX0, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_0, VALID_OPTIONS_SBOX},
    {"SBOX0C1",PMC68, SBOX0, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_0, VALID_OPTIONS_SBOX},
    {"SBOX0C2",PMC69, SBOX0, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_0, VALID_OPTIONS_SBOX},
    {"SBOX0C3",PMC70, SBOX0, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_0, VALID_OPTIONS_SBOX},
    {"SBOX1C0",PMC71, SBOX1, PCI_UNC_QPI_PMON_CTL_0, PCI_UNC_QPI_PMON_CTR_0_A, PCI_UNC_QPI_PMON_CTR_0_B, PCI_QPI_DEVICE_PORT_1, VALID_OPTIONS_SBOX},
    {"SBOX1C1",PMC72, SBOX1, PCI_UNC_QPI_PMON_CTL_1, PCI_UNC_QPI_PMON_CTR_1_A, PCI_UNC_QPI_PMON_CTR_1_B, PCI_QPI_DEVICE_PORT_1, VALID_OPTIONS_SBOX},
    {"SBOX1C2",PMC73, SBOX1, PCI_UNC_QPI_PMON_CTL_2, PCI_UNC_QPI_PMON_CTR_2_A, PCI_UNC_QPI_PMON_CTR_2_B, PCI_QPI_DEVICE_PORT_1, VALID_OPTIONS_SBOX},
    {"SBOX1C3",PMC74, SBOX1, PCI_UNC_QPI_PMON_CTL_3, PCI_UNC_QPI_PMON_CTR_3_A, PCI_UNC_QPI_PMON_CTR_3_B, PCI_QPI_DEVICE_PORT_1, VALID_OPTIONS_SBOX},
    /* BBOX or better known as Home Agent (HA) */
    {"BBOX0",PMC75, BBOX0, PCI_UNC_HA_PMON_CTL_0, PCI_UNC_HA_PMON_CTR_0_A, PCI_UNC_HA_PMON_CTR_0_B, PCI_HA_DEVICE, VALID_OPTIONS_BBOX},
    {"BBOX1",PMC76, BBOX0, PCI_UNC_HA_PMON_CTL_1, PCI_UNC_HA_PMON_CTR_1_A, PCI_UNC_HA_PMON_CTR_1_B, PCI_HA_DEVICE, VALID_OPTIONS_BBOX},
    {"BBOX2",PMC77, BBOX0, PCI_UNC_HA_PMON_CTL_2, PCI_UNC_HA_PMON_CTR_2_A, PCI_UNC_HA_PMON_CTR_2_B, PCI_HA_DEVICE, VALID_OPTIONS_BBOX},
    {"BBOX3",PMC78, BBOX0, PCI_UNC_HA_PMON_CTL_3, PCI_UNC_HA_PMON_CTR_3_A, PCI_UNC_HA_PMON_CTR_3_B, PCI_HA_DEVICE, VALID_OPTIONS_BBOX},
    {"WBOX0",PMC79, WBOX, MSR_UNC_PCU_PMON_CTL0, MSR_UNC_PCU_PMON_CTR0, 0, 0, VALID_OPTIONS_WBOX},
    {"WBOXFIXC3", PMC80, WBOXFIXC3, 0, MSR_UNC_PCU_PMON_BOX_CTL1, 0, 0, EVENT_OPTION_NONE_MASK},
    {"WBOXFIXC6", PMC81, WBOXFIXC6, 0, MSR_UNC_PCU_PMON_BOX_CTL2, 0, 0, EVENT_OPTION_NONE_MASK}
};
