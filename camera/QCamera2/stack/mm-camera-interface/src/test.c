#include <stdio.h>
#include <stdint.h>

#define INCLUDE(PARAM_ID,DATATYPE,COUNT)  \
        DATATYPE member_variable_##PARAM_ID[ COUNT ]

#define MAX_ROI 10

typedef struct {
	char name[32];
} cam_fw_cl_number_t;

typedef struct {
	char test[12];
} cam_internal_fd_ae;

typedef struct {
    float min_fps;
    float max_fps;
} cam_fps_range_t;

typedef enum {
    CAM_AEC_ROI_OFF,
    CAM_AEC_ROI_ON
} cam_aec_roi_ctrl_t;

typedef enum {
    CAM_AEC_ROI_BY_INDEX,
    CAM_AEC_ROI_BY_COORDINATE,
} cam_aec_roi_type_t;

typedef struct {
    uint32_t x;
    uint32_t y;
} cam_coordinate_type_t;

typedef struct {
    cam_aec_roi_ctrl_t aec_roi_enable;
    cam_aec_roi_type_t aec_roi_type;
    union {
        cam_coordinate_type_t coordinate[MAX_ROI];
        uint32_t aec_roi_idx[MAX_ROI];
    } cam_aec_roi_position;
} cam_set_aec_roi_t;

typedef struct  {
    int32_t left;
    int32_t top;
    int32_t width;
    int32_t height;
} cam_rect_t;

typedef struct {
    uint32_t frm_id;
    uint8_t num_roi;
    cam_rect_t roi[MAX_ROI];
    int32_t weight[MAX_ROI];
    uint8_t is_multiwindow;
} cam_roi_info_t;

typedef struct {
    int fd_mode;               /* mask of face process */
    int num_fd;
} cam_fd_set_parm_t;

typedef enum {
    CAM_WAVELET_DENOISE_YCBCR_PLANE,
    CAM_WAVELET_DENOISE_CBCR_ONLY,
    CAM_WAVELET_DENOISE_STREAMLINE_YCBCR,
    CAM_WAVELET_DENOISE_STREAMLINED_CBCR
} cam_denoise_process_type_t;

typedef struct {
    int denoise_enable;
    cam_denoise_process_type_t process_plates;
} cam_denoise_param_t;

typedef enum {
    CAM_EXP_BRACKETING_OFF,
    CAM_EXP_BRACKETING_ON
} cam_bracket_mode;

#define MAX_EXP_BRACKETING_LENGTH 32

typedef struct {
    cam_bracket_mode mode;
    char values[MAX_EXP_BRACKETING_LENGTH];  /* user defined values */
} cam_exp_bracketing_t;

typedef struct {
    int32_t width;
    int32_t height;
} cam_dimension_t;

#define MAX_STREAM_NUM_IN_BUNDLE 4

typedef struct {
    uint32_t bundle_id;                            /* bundle id */
    uint8_t num_of_streams;                        /* number of streams in the bundle */
    uint32_t stream_ids[MAX_STREAM_NUM_IN_BUNDLE]; /* array of stream ids to be bundled */
} cam_bundle_config_t;

typedef union {
/**************************************************************************************
 *          ID from (cam_intf_parm_type_t)          DATATYPE                     COUNT
 **************************************************************************************/
    int32_t member_variable_CAM_INTF_PARM_SHOT_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_ANTISHAKE[1];
    int32_t member_variable_CAM_INTF_PARM_DUAL_MODE[1];
    int32_t member_variable_field_36[1];
    int32_t member_variable_CAM_INTF_PARM_LLV[1];
    int32_t member_variable_CAM_INTF_PARM_FIRMWARE_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_0[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_1[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_2[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_3[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_4[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_5[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_6[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_7[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_8[1];
} my_parm_type;

typedef union {
/**************************************************************************************
 *          ID from (cam_intf_parm_type_t)          DATATYPE                     COUNT
 **************************************************************************************/
    int32_t member_variable_CAM_INTF_PARM_QUERY_FLASH4SNAP[1];
    int32_t member_variable_CAM_INTF_PARM_EXPOSURE[1];
    int32_t member_variable_CAM_INTF_PARM_SHARPNESS[1];
    int32_t member_variable_CAM_INTF_PARM_CONTRAST[1];
    int32_t member_variable_CAM_INTF_PARM_SATURATION[1];
    int32_t member_variable_CAM_INTF_PARM_BRIGHTNESS[1];
    int32_t member_variable_CAM_INTF_PARM_WHITE_BALANCE[1];
    int32_t member_variable_CAM_INTF_PARM_ISO[1];
    int32_t member_variable_CAM_INTF_PARM_ANTIBANDING[1];
    int32_t member_variable_CAM_INTF_PARM_EFFECT[1];
    cam_fps_range_t member_variable_CAM_INTF_PARM_FPS_RANGE[1];
    int32_t member_variable_CAM_INTF_PARM_EXPOSURE_COMPENSATION[1];
    int32_t member_variable_CAM_INTF_PARM_LED_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_ROLLOFF[1];
    int32_t member_variable_CAM_INTF_PARM_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_AEC_ALGO_TYPE[1];
    int32_t member_variable_CAM_INTF_PARM_FOCUS_ALGO_TYPE[1];
    cam_set_aec_roi_t member_variable_CAM_INTF_PARM_AEC_ROI[1];
    cam_roi_info_t member_variable_CAM_INTF_PARM_AF_ROI[1];
    int32_t member_variable_CAM_INTF_PARM_FOCUS_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_BESTSHOT_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_SCE_FACTOR[1];
    cam_internal_fd_ae member_variable_CAM_INTF_PARM_FD[1];
    int32_t member_variable_CAM_INTF_PARM_AEC_LOCK[1];
    int32_t member_variable_CAM_INTF_PARM_AWB_LOCK[1];
    int32_t member_variable_CAM_INTF_PARM_MCE[1];
    int32_t member_variable_CAM_INTF_PARM_HFR[1];
    int32_t member_variable_CAM_INTF_PARM_REDEYE_REDUCTION[1];
    cam_denoise_param_t member_variable_CAM_INTF_PARM_WAVELET_DENOISE[1];
    int32_t member_variable_CAM_INTF_PARM_ASD_ENABLE[1];
    int32_t member_variable_CAM_INTF_PARM_RECORDING_HINT[1];
    int32_t member_variable_CAM_INTF_PARM_DIS_ENABLE[1];
    cam_exp_bracketing_t member_variable_CAM_INTF_PARM_HDR[1];
    int32_t member_variable_CAM_INTF_PARM_FRAMESKIP[1];
    int32_t member_variable_CAM_INTF_PARM_ZSL_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_HDR_NEED_1X[1];
    int32_t member_variable_CAM_INTF_PARM_LOCK_CAF[1];
    int32_t member_variable_CAM_INTF_PARM_VIDEO_HDR[1];
    cam_dimension_t member_variable_CAM_INTF_PARM_UPDATE_RAW[1];
    int32_t member_variable_field_24[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_APP[1];
    int32_t member_variable_CAM_INTF_PARM_OCRAF_ENABLE[1];
    int32_t member_variable_CAM_INTF_PARM_OCRAF_WINDOW[1];
    int32_t member_variable_CAM_INTF_PARM_VISION_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_VISION_AE[1];
    int32_t member_variable_field_2F[1];
    int32_t member_variable_field_30[1];
    int32_t member_variable_field_31[1];
    cam_bundle_config_t member_variable_CAM_INTF_PARM_BUNDLE_INFO[1];
    int32_t member_variable_CAM_INTF_PARM_SHOT_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_ANTISHAKE[1];
    int32_t member_variable_CAM_INTF_PARM_DUAL_MODE[1];
    cam_fw_cl_number_t member_variable_CAM_INTF_PARM_FW_CL_NUMBER[1];
    int32_t member_variable_CAM_INTF_PARM_LLV[1];
    int32_t member_variable_CAM_INTF_PARM_FIRMWARE_MODE[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_0[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_1[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_2[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_3[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_4[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_5[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_6[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_7[1];
    int32_t member_variable_CAM_INTF_PARM_SAMSUNG_8[1];
} my_parm_type_t;

typedef enum {
    CAM_FORMAT_JPEG = 0,
    CAM_FORMAT_YUV_420_NV12 = 1,
    CAM_FORMAT_YUV_420_NV21,
    CAM_FORMAT_YUV_420_NV21_ADRENO,
    CAM_FORMAT_YUV_420_YV12,
    CAM_FORMAT_YUV_422_NV16,
    CAM_FORMAT_YUV_422_NV61,
    CAM_FORMAT_YUV_420_NV12_VENUS,

    /* Please note below are the defintions for raw image.
     * Any format other than raw image format should be declared
     * before this line!!!!!!!!!!!!! */

    /* Note: For all raw formats, each scanline needs to be 16 bytes aligned */

    /* Packed YUV/YVU raw format, 16 bpp: 8 bits Y and 8 bits UV.
     * U and V are interleaved with Y: YUYV or YVYV */
    CAM_FORMAT_YUV_RAW_8BIT_YUYV,
    CAM_FORMAT_YUV_RAW_8BIT_YVYU,
    CAM_FORMAT_YUV_RAW_8BIT_UYVY,
    CAM_FORMAT_YUV_RAW_8BIT_VYUY,

    /* QCOM RAW formats where data is packed into 64bit word.
     * 8BPP: 1 64-bit word contains 8 pixels p0 - p7, where p0 is
     *       stored at LSB.
     * 10BPP: 1 64-bit word contains 6 pixels p0 - p5, where most
     *       significant 4 bits are set to 0. P0 is stored at LSB.
     * 12BPP: 1 64-bit word contains 5 pixels p0 - p4, where most
     *       significant 4 bits are set to 0. P0 is stored at LSB. */
    CAM_FORMAT_BAYER_QCOM_RAW_8BPP_GBRG,
    CAM_FORMAT_BAYER_QCOM_RAW_8BPP_GRBG,
    CAM_FORMAT_BAYER_QCOM_RAW_8BPP_RGGB,
    CAM_FORMAT_BAYER_QCOM_RAW_8BPP_BGGR,
    CAM_FORMAT_BAYER_QCOM_RAW_10BPP_GBRG,
    CAM_FORMAT_BAYER_QCOM_RAW_10BPP_GRBG,
    CAM_FORMAT_BAYER_QCOM_RAW_10BPP_RGGB,
    CAM_FORMAT_BAYER_QCOM_RAW_10BPP_BGGR,
    CAM_FORMAT_BAYER_QCOM_RAW_12BPP_GBRG,
    CAM_FORMAT_BAYER_QCOM_RAW_12BPP_GRBG,
    CAM_FORMAT_BAYER_QCOM_RAW_12BPP_RGGB,
    CAM_FORMAT_BAYER_QCOM_RAW_12BPP_BGGR,
    /* MIPI RAW formats based on MIPI CSI-2 specifiction.
     * 8BPP: Each pixel occupies one bytes, starting at LSB.
     *       Output with of image has no restrictons.
     * 10BPP: Four pixels are held in every 5 bytes. The output
     *       with of image must be a multiple of 4 pixels.
     * 12BPP: Two pixels are held in every 3 bytes. The output
     *       width of image must be a multiple of 2 pixels. */
    CAM_FORMAT_BAYER_MIPI_RAW_8BPP_GBRG,
    CAM_FORMAT_BAYER_MIPI_RAW_8BPP_GRBG,
    CAM_FORMAT_BAYER_MIPI_RAW_8BPP_RGGB,
    CAM_FORMAT_BAYER_MIPI_RAW_8BPP_BGGR,
    CAM_FORMAT_BAYER_MIPI_RAW_10BPP_GBRG,
    CAM_FORMAT_BAYER_MIPI_RAW_10BPP_GRBG,
    CAM_FORMAT_BAYER_MIPI_RAW_10BPP_RGGB,
    CAM_FORMAT_BAYER_MIPI_RAW_10BPP_BGGR,
    CAM_FORMAT_BAYER_MIPI_RAW_12BPP_GBRG,
    CAM_FORMAT_BAYER_MIPI_RAW_12BPP_GRBG,
    CAM_FORMAT_BAYER_MIPI_RAW_12BPP_RGGB,
    CAM_FORMAT_BAYER_MIPI_RAW_12BPP_BGGR,
    /* Ideal raw formats where image data has gone through black
     * correction, lens rolloff, demux/channel gain, bad pixel
     * correction, and ABF.
     * Ideal raw formats could output any of QCOM_RAW and MIPI_RAW
     * formats, plus plain8 8bbp, plain16 800, plain16 10bpp, and
     * plain 16 12bpp */
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_8BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_8BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_8BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_8BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_10BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_10BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_10BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_10BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_12BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_12BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_12BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_QCOM_12BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_8BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_8BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_8BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_8BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_10BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_10BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_10BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_10BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_12BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_12BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_12BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_MIPI_12BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN8_8BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN8_8BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN8_8BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN8_8BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_8BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_8BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_8BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_8BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_10BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_10BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_10BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_10BPP_BGGR,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_12BPP_GBRG,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_12BPP_GRBG,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_12BPP_RGGB,
    CAM_FORMAT_BAYER_IDEAL_RAW_PLAIN16_12BPP_BGGR,

    /* generic 8-bit raw */
    CAM_FORMAT_JPEG_RAW_8BIT,
    CAM_FORMAT_META_RAW_8BIT,

    CAM_FORMAT_MAX
} cam_format_t;

int main() {
	printf("sizeof is %lu vs %lu", sizeof(my_parm_type_t), sizeof(cam_set_aec_roi_t));
	printf("size is %d", CAM_FORMAT_MAX);
}
