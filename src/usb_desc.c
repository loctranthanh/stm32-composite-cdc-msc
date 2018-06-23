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
  		0x12,   /* bLength */
			USB_DEVICE_DESCRIPTOR_TYPE,     /* bDescriptorType */
			0x00,
			0x02,   /* bcdUSB = 2.00 */
			0xEF,   /* bDeviceClass: CDC */
			0x02,   /* bDeviceSubClass */
			0x01,   /* bDeviceProtocol */
			0x40,   /* bMaxPacketSize0 */
			0x83,
			0x04,   /* idVendor = 0x0483 */
			0x40,
			0x57,   /* idProduct = 0x7540 */
			0x00,
			0x02,   /* bcdDevice = 2.00 */
			1,              /* Index of string descriptor describing manufacturer */
			2,              /* Index of string descriptor describing product */
			3,              /* Index of string descriptor describing the device's serial number */
			0x01    /* bNumConfigurations */
  };
const uint8_t MASS_ConfigDescriptor[MASS_SIZ_CONFIG_DESC] =
  {
  		0x09, /* bLength: Configuration Descriptor size */
			USB_CONFIGURATION_DESCRIPTOR_TYPE, /* bDescriptorType: Configuration */
			Composite_SIZ_CONFIG_DESC,
			0x00,
			0x0,         /* bNumInterfaces: 2 interfaces */
			0x01,         /* bConfigurationValue: Configuration value */
			0x00,         /* iConfiguration: Index of string descriptor describing */
			0xC0,         /* bmAttributes: Self powered */
			0x32,         /* MaxPower 100 mA: this current is used for detecting Vbus */
			0x09,   /* bLength: Interface Descriptor size */
			0x04,   /* bDescriptorType: */
			0x01,   /* bInterfaceNumber: Number of Interface */
			0x00,   /* bAlternateSetting: Alternate setting */
			0x02,   /* bNumEndpoints*/
			0x08,   /* bInterfaceClass: MASS STORAGE Class */
			0x06,   /* bInterfaceSubClass : SCSI transparent*/
			0x50,   /* nInterfaceProtocol */
			1,          /* iInterface: */
			0x07,   /*Endpoint descriptor length = 7*/
			0x05,   /*Endpoint descriptor type */
			0x81,   /*Endpoint address (IN, address 2) */
			0x02,   /*Bulk endpoint type */
			0x40,   /*Maximum packet size (64 bytes) */
			0x00,
			0x00,   /*Polling interval in milliseconds */
			0x07,   /*Endpoint descriptor length = 7 */
			0x05,   /*Endpoint descriptor type */
			0x02,   /*Endpoint address (OUT, address 2) */
			0x02,   /*Bulk endpoint type */
			0x40,   /*Maximum packet size (64 bytes) */
			0x00,
			0x00,     /*Polling interval in milliseconds*/
						// IAD
			0x08, /* bLength */
			0x0B, /* bDescriptorType */
			0x1, /* bFirstInterface */
			0x02, /* bInterfaceCount */
			0x02, /* bFunctionClass */
			0x02, /* bFunctionSubClass */
			0x01, /* bFunctionProtocol */
			0x00, /* iFunction (Index of string descriptor describing this function) */
						// CDC
			0x09,   /* bLength: Interface Descriptor size */
			USB_INTERFACE_DESCRIPTOR_TYPE,  /* bDescriptorType: Interface */
			0x00,   /* bInterfaceNumber: Number of Interface */
			0x00,   /* bAlternateSetting: Alternate setting */
			0x01,   /* bNumEndpoints: One endpoints used */
			0x02,   /* bInterfaceClass: Communication Interface Class */
			0x02,   /* bInterfaceSubClass: Abstract Control Model */
			0x01,   /* bInterfaceProtocol: Common AT commands */
			0x00,   /* iInterface: */
			0x05,   /* bLength: Endpoint Descriptor size */
			0x24,   /* bDescriptorType: CS_INTERFACE */
			0x00,   /* bDescriptorSubtype: Header Func Desc */
			0x10,   /* bcdCDC: spec release number */
			0x01,
			0x05,   /* bFunctionLength */
			0x24,   /* bDescriptorType: CS_INTERFACE */
			0x01,   /* bDescriptorSubtype: Call Management Func Desc */
			0x00,   /* bmCapabilities: D0+D1 */
			0x01,   /* bDataInterface: 1 */
			0x04,   /* bFunctionLength */
			0x24,   /* bDescriptorType: CS_INTERFACE */
			0x02,   /* bDescriptorSubtype: Abstract Control Management desc */
			0x02,   /* bmCapabilities */
			0x05,   /* bFunctionLength */
			0x24,   /* bDescriptorType: CS_INTERFACE */
			0x06,   /* bDescriptorSubtype: Union func desc */
			0x00,   /* bMasterInterface: Communication class interface */
			0x01,   /* bSlaveInterface0: Data Class Interface */
					// Interface desc
			0x07,   /* bLength: Endpoint Descriptor size */
			USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
			0x82,   /* bEndpointAddress: (IN2) */
			0x03,   /* bmAttributes: Interrupt */
			VIRTUAL_COM_PORT_INT_SIZE,      /* wMaxPacketSize: */
			0x00,
			0xFF,   /* bInterval: */
					// Endpoint desc
			0x09,   /* bLength: Endpoint Descriptor size */
			USB_INTERFACE_DESCRIPTOR_TYPE,  /* bDescriptorType: */
			0x01,   /* bInterfaceNumber: Number of Interface */
			0x00,   /* bAlternateSetting: Alternate setting */
			0x02,   /* bNumEndpoints: Two endpoints used */
			0x0A,   /* bInterfaceClass: CDC */
			0x00,   /* bInterfaceSubClass: */
			0x00,   /* bInterfaceProtocol: */
			0x00,   /* iInterface: */
			0x07,   /* bLength: Endpoint Descriptor size */
			USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
			0x03,   /* bEndpointAddress: (OUT3) */
			0x02,   /* bmAttributes: Bulk */
			VIRTUAL_COM_PORT_DATA_SIZE,             /* wMaxPacketSize: */
			0x00,
			0x00,   /* bInterval: ignore for Bulk transfer */
			0x07,   /* bLength: Endpoint Descriptor size */
			USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
			0x83,   /* bEndpointAddress: (IN1) */
			0x02,   /* bmAttributes: Bulk */
			VIRTUAL_COM_PORT_DATA_SIZE,             /* wMaxPacketSize: */
			0x00,
			0x00    /* bInterval */
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
