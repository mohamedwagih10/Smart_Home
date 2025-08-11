/*
 * SPI_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Dell
 */

#ifndef MCAL_SPI_SPI_CFG_H_
#define MCAL_SPI_SPI_CFG_H_
/*
 * MASTER
 * SLAVE
 */
#define SPI_TYPE MASTER
/*
 * LSB
 * MSB
 */
#define DATA_ORDER LSB
/** select SPI clock rate
  ** Options
      **PRESCALLER_2
	  **PRESCALLER_16
	  **PRESCALLER_64
	  **PRESCALLER_128
	  **PRESCALLER_2
	  **PRESCALLER_8
	  **PRESCALLER_32
 */
#define SPI_CLOCK_RATE  PRESCALLER_16

#endif /* MCAL_SPI_SPI_CFG_H_ */
