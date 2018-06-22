/******************** (C) COPYRIGHT 2010 STMicroelectronics ********************
* File Name          : usb_desc.c
* Author             : MCD Application Team
* Version            : V3.2.1
* Date               : 07/05/2010
* Description        : Descriptors for Mass Storage Device
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "usb_desc.h"

const uint8_t MASS_DeviceDescriptor[MASS_SIZ_DEVICE_DESC] =
  {
  		0x12,                       /*bLength */
			USB_DEVICE_DESCRIPTOR_TYPE, /*bDescriptorType*/
			0x00,                       /*bcdUSB */
			0x02,
			0x00,                       /*bDeviceClass*/
			0x00,                       /*bDeviceSubClass*/
			0x00,                       /*bDeviceProtocol*/
			0x40,                       /*bMaxPacketSize40*/
			0x83,                       /*idVendor (0x0483)*/
			0x04,
			0x50,                       /*idProduct = 0x5750*/
			0x57,
			0x00,                       /*bcdDevice rel. 2.00*/
			0x02,
			1,                          /*Index of string descriptor describing
																								manufacturer */
			2,                          /*Index of string descriptor describing
																							 product*/
			3,                          /*Index of string descriptor describing the
																							 device serial number */
			0x01                        /*bNumConfigurations*/
  };
const uint8_t MASS_ConfigDescriptor[MASS_SIZ_CONFIG_DESC] =
  {
  		0x09, /* bLength: Configuration Descriptor size */
			USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration */
			Composite_SIZ_CONFIG_DESC,
			/* wTotalLength: Bytes returned */
			0x00,
			0x02,         /* bNumInterfaces: 2 interfaces */
			0x01,         /* bConfigurationValue: Configuration value */
			0x00,         /* iConfiguration: Index of string descriptor describing
																	 the configuration*/
			0xC0,         /* bmAttributes: Self powered */
			0x32,         /* MaxPower 100 mA: this current is used for detecting Vbus */

			/************** Descriptor of Custom HID interface ****************/
			/* 09 */
			0x09,         /* bLength: Interface Descriptor size */
			USB_INTERFACE_DESCRIPTOR_TYPE,/* bDescriptorType: Interface descriptor type */
			0x00,         /* bInterfaceNumber: Number of Interface */
			0x00,         /* bAlternateSetting: Alternate setting */
			0x02,         /* bNumEndpoints */
			0x03,         /* bInterfaceClass: HID */
			0x00,         /* bInterfaceSubClass : 1=BOOT, 0=no boot */
			0x00,         /* nInterfaceProtocol : 0=none, 1=keyboard, 2=mouse */
			0,            /* iInterface: Index of string descriptor */
			/******************** Descriptor of Custom HID HID ********************/
			/* 18 */
			0x09,         /* bLength: HID Descriptor size */
			HID_DESCRIPTOR_TYPE, /* bDescriptorType: HID */
			0x10,         /* bcdHID: HID Class Spec release number */
			0x01,
			0x00,         /* bCountryCode: Hardware target country */
			0x01,         /* bNumDescriptors: Number of HID class descriptors to follow */
			0x22,         /* bDescriptorType */
			CUSTOMHID_SIZ_REPORT_DESC,/* wItemLength: Total length of Report descriptor */
			0x00,
			/******************** Descriptor of Custom HID endpoints ******************/
			/* 27 */
			0x07,          /* bLength: Endpoint Descriptor size */
			USB_ENDPOINT_DESCRIPTOR_TYPE, /* bDescriptorType: */

			0x82,          /* bEndpointAddress: Endpoint Address (IN) */
			0x03,          /* bmAttributes: Interrupt endpoint */
			0x02,          /* wMaxPacketSize: 2 Bytes max */
			0x00,
			0x20,          /* bInterval: Polling Interval (32 ms) */
			/* 34 */

			0x07,	/* bLength: Endpoint Descriptor size */
			USB_ENDPOINT_DESCRIPTOR_TYPE,	/* bDescriptorType: */
				/*	Endpoint descriptor type */
			0x01,	/* bEndpointAddress: */
				/*	Endpoint Address (OUT) */
			0x03,	/* bmAttributes: Interrupt endpoint */
			0x02,	/* wMaxPacketSize: 2 Bytes max  */
			0x00,
			0x20,	/* bInterval: Polling Interval (20 ms) */
			/* 41 */
			/******************** Descriptor of Mass Storage interface ********************/
			/* 09 */
			0x09,   /* bLength: Interface Descriptor size */
			0x04,   /* bDescriptorType: */
			/*      Interface descriptor type */
			0x01,   /* bInterfaceNumber: Number of Interface */
			0x00,   /* bAlternateSetting: Alternate setting */
			0x02,   /* bNumEndpoints*/
			0x08,   /* bInterfaceClass: MASS STORAGE Class */
			0x06,   /* bInterfaceSubClass : SCSI transparent*/
			0x50,   /* nInterfaceProtocol */
			1,          /* iInterface: */
			/* 18 */
			0x07,   /*Endpoint descriptor length = 7*/
			0x05,   /*Endpoint descriptor type */
			0x81,   /*Endpoint address (IN, address 2) */
			0x02,   /*Bulk endpoint type */
			0x40,   /*Maximum packet size (64 bytes) */
			0x00,
			0x00,   /*Polling interval in milliseconds */
			/* 25 */
			0x07,   /*Endpoint descriptor length = 7 */
			0x05,   /*Endpoint descriptor type */
			0x02,   /*Endpoint address (OUT, address 2) */
			0x02,   /*Bulk endpoint type */
			0x40,   /*Maximum packet size (64 bytes) */
			0x00,
			0x00     /*Polling interval in milliseconds*/
			/*32*/
  };
const uint8_t MASS_StringLangID[MASS_SIZ_STRING_LANGID] =
  {
    MASS_SIZ_STRING_LANGID,
    0x03,
    0x09,
    0x04
  }
  ;      /* LangID = 0x0409: U.S. English */
const uint8_t MASS_StringVendor[MASS_SIZ_STRING_VENDOR] =
  {
    MASS_SIZ_STRING_VENDOR, /* Size of manufaturer string */
    0x03,           /* bDescriptorType = String descriptor */
    /* Manufacturer: "WWW.powermcu.com" */   	
    'W', 0, 'W', 0, 'W', 0, '.', 0, 'P', 0, 'o', 0, 'w', 0, 'e', 0,
    'r', 0, 'M', 0, 'C', 0, 'U', 0, '.', 0, 'C', 0, 'O', 0, 'M', 0,
  };
const uint8_t MASS_StringProduct[MASS_SIZ_STRING_PRODUCT] =
  {
    MASS_SIZ_STRING_PRODUCT,
    0x03,
  	/* Multi Media Development Board V1.0 */
    'M', 0, 'u', 0, 'l', 0, 't', 0, 'i', 0, ' ', 0, 'M', 0,
    'e', 0, 'd', 0, 'i', 0, 'a', 0, ' ', 0, 'D', 0, 'e', 0,	
    'v', 0, 'e', 0, 'l', 0, 'o', 0, 'p', 0, 'm', 0, 'e', 0,
	'n', 0, 't', 0, ' ', 0, 'B', 0, 'o', 0, 'a', 0, 'r', 0,
	'd', 0, ' ', 0, 'V', 0, '1', 0, '.', 0, '0'
  };

uint8_t MASS_StringSerial[MASS_SIZ_STRING_SERIAL] =
  {
    MASS_SIZ_STRING_SERIAL,
    0x03,
    /* Serial number*/
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, '1', 0, '0', 0
  };
const uint8_t MASS_StringInterface[MASS_SIZ_STRING_INTERFACE] =
  {
    MASS_SIZ_STRING_INTERFACE,
    0x03,
    /* Interface 0: "ST Mass" */
    'S', 0, 'T', 0, ' ', 0, 'M', 0, 'a', 0, 's', 0, 's', 0
  };

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
