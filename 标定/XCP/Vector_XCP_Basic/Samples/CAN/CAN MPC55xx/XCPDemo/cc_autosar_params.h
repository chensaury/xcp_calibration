// Define or declare all parameters in the calibration concept CC_AUTOSAR or CC_INCIRCUIT


#ifdef DECLARE_PARAMETERS_DONE
  #undef DECLARE_PARAMETERS
#else
  #define DECLARE_PARAMETERS_DONE
#endif

// Datatypes
#define UINT64 unsigned long long
#define UINT32 unsigned int
#define UINT16 unsigned short
#define UINT8 unsigned char
#define INT64 signed long long
#define INT32 signed int
#define INT16 signed short
#define INT8 signed char
#define FLOAT float
#define DOUBLE double

#define CC_ATTRIBUTE_CALFLASH __attribute__((section("calflash")))

// All parameters are accessed indirectly via CC_PTR_TABLE
#ifdef CC_DOUBLE_POINTERED
  #define CC_PTR_TABLE (*gCC_Pointer)
#else
  #define CC_PTR_TABLE gCC_SetPtrRamTable
#endif

// ADC calibration
#define CC_SET_1 cal_set_adc
#ifdef DECLARE_PARAMETERS
	struct cal_set_adc {
    FLOAT _adc_min;
    FLOAT _adc_max;
    FLOAT _adc_offset;
	}; 
	extern volatile const struct cal_set_adc cal_set_adc;
#endif
#ifdef DEFINE_PARAMETERS
	CC_ATTRIBUTE_CALFLASH volatile const struct cal_set_adc cal_set_adc = { 
	  -1, +1, -8096 
	};
#endif
#if !defined(CC_AUTOSAR) && !defined(CC_INCIRCUIT)
  #define adc_min     cal_set_adc._adc_min
  #define adc_max     cal_set_adc._adc_max
  #define adc_offset  cal_set_adc._adc_offset
#else
  #define adc_min     CC_PTR_TABLE.cal_set_adc->_adc_min
  #define adc_max     CC_PTR_TABLE.cal_set_adc->_adc_max
  #define adc_offset  CC_PTR_TABLE.cal_set_adc->_adc_offset
#endif

// Calibration demo	(led pattern)
#define CC_SET_2 cal_set_led
#ifdef DECLARE_PARAMETERS
struct cal_set_led {
  UINT8 _led_pattern[16];	   
}; 
extern volatile const struct cal_set_led cal_set_led;
#endif
#ifdef DEFINE_PARAMETERS
CC_ATTRIBUTE_CALFLASH volatile const struct cal_set_led cal_set_led = { 
  {0x03,0x03,0x03,0x03,0x01,0x01,0x01,0x01,0x02,0x02,0x02,0x02,0x00,0x00,0x00,0x00}, 
};          
#endif
#if !defined(CC_AUTOSAR) && !defined(CC_INCIRCUIT)
  #define led_pattern cal_set_led._led_pattern
#else
  #define led_pattern CC_PTR_TABLE.cal_set_led->_led_pattern
#endif

// Calibration demo (various data types)
#define CC_SET_3 cal_set_demo
#ifdef DECLARE_PARAMETERS
	struct cal_set_demo {
	  UINT8 _cal_test_ub;		  
	  UINT16 _cal_test_uw;	  
	  UINT32 _cal_test_ul;      
    FLOAT _cal_test_float;    
    DOUBLE _cal_test_double;
    UINT32 _cal_test_array[16];
	}; 
	extern volatile const struct cal_set_demo cal_set_demo;
#endif
#ifdef DEFINE_PARAMETERS
	CC_ATTRIBUTE_CALFLASH volatile const struct cal_set_demo cal_set_demo = { 
	  1,
	  2,
	  3,
    0.12345678901234567890,
    0.12345678901234567890,
    { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }
	};
#endif
#if !defined(CC_AUTOSAR) && !defined(CC_INCIRCUIT)
  #define cal_test_ub cal_set_demo._cal_test_ub
  #define cal_test_uw cal_set_demo._cal_test_uw
  #define cal_test_ul cal_set_demo._cal_test_ul
  #define cal_test_float cal_set_demo._cal_test_float
  #define cal_test_double cal_set_demo._cal_test_double
  #define cal_test_array cal_set_demo._cal_test_array
#else
  #define cal_test_ub CC_PTR_TABLE.cal_set_demo->_cal_test_ub
  #define cal_test_uw CC_PTR_TABLE.cal_set_demo->_cal_test_uw
  #define cal_test_ul CC_PTR_TABLE.cal_set_demo->_cal_test_ul
  #define cal_test_float CC_PTR_TABLE.cal_set_demo->_cal_test_float
  #define cal_test_double CC_PTR_TABLE.cal_set_demo->_cal_test_double
  #define cal_test_array CC_PTR_TABLE.cal_set_demo->_cal_test_array
#endif


// Calibration demo (various data types)
#define CC_SET_4 cal_set_demo2
#ifdef DECLARE_PARAMETERS
	struct cal_set_demo2 {
    UINT8 _cal_test_matrix[8][8];
	}; 
	extern volatile const struct cal_set_demo2 cal_set_demo2;
#endif
#ifdef DEFINE_PARAMETERS
	CC_ATTRIBUTE_CALFLASH volatile const struct cal_set_demo2 cal_set_demo2 = { 
   {{ 0,1,2,3,4,5,6,7 },
    { 0,1,2,3,4,5,6,7 },
    { 0,1,2,3,4,5,6,7 },
    { 0,1,2,3,4,5,6,7 },
    { 0,1,2,3,4,5,6,7 },
    { 0,1,2,3,4,5,6,7 },
    { 0,1,2,3,4,5,6,7 },
    { 0,1,2,3,4,5,6,7 }}
	};
#endif
#if !defined(CC_AUTOSAR) && !defined(CC_INCIRCUIT)
  #define cal_test_matrix cal_set_demo2._cal_test_matrix
#else
  #define cal_test_matrix CC_PTR_TABLE.cal_set_demo2->_cal_test_matrix
#endif
  

#undef DECLARE_PARAMETERS
#undef DEFINE_PARAMETERS
