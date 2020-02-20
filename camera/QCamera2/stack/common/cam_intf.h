/* Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __QCAMERA_INTF_H__
#define __QCAMERA_INTF_H__

#include <media/msmb_isp.h>
#include "cam_types.h"

#define CAM_PRIV_IOCTL_BASE (V4L2_CID_PRIVATE_BASE + 14)
typedef enum {
    CAM_PRIV_PARM = CAM_PRIV_IOCTL_BASE, /* session based parameters */
    CAM_PRIV_DO_AUTO_FOCUS,              /* session based action: do auto focus */
    CAM_PRIV_CANCEL_AUTO_FOCUS,          /* session based action: cancel auto focus */
    CAM_PRIV_PREPARE_SNAPSHOT,           /* session based action: prepare for snapshot */
    CAM_PRIV_STREAM_INFO_SYNC,           /* sync stream info */
    CAM_PRIV_STREAM_PARM,                /* stream based parameters */
    CAM_PRIV_START_ZSL_SNAPSHOT,         /* start ZSL snapshot */
    CAM_PRIV_STOP_ZSL_SNAPSHOT,          /* stop ZSL snapshot */
} cam_private_ioctl_enum_t;

/* capability struct definition */
typedef struct{
  uint32_t sony_camera; //guessed
  uint32_t position;
  uint32_t sensor_mount_angle;
  uint32_t modes_supported; //guessed
  float focal_length;
  float hor_view_angle;
  float ver_view_angle;
  uint8_t zoom_ratio_tbl_cnt;
  int zoom_ratio_tbl[64];
  uint8_t preview_sizes_tbl_cnt;
  cam_dimension_t preview_sizes_tbl[30];
  uint8_t video_sizes_tbl_cnt;
  cam_dimension_t video_sizes_tbl[30];
  uint8_t picture_sizes_tbl_cnt;
  cam_dimension_t picture_sizes_tbl[30];
  uint8_t fps_ranges_tbl_cnt;
  cam_fps_range_t fps_ranges_tbl[30];
  uint8_t livesnapshot_sizes_tbl_cnt;
  cam_dimension_t livesnapshot_sizes_tbl[30];
  uint8_t hfr_tbl_cnt;
  cam_hfr_info_t hfr_tbl[5];
  uint8_t supported_preview_fmt_cnt;
  cam_format_t supported_preview_fmts[78];
  uint8_t supported_picture_fmts_cnt;
  cam_format_t supported_picture_fmts[78];
  cam_dimension_t raw_dim;
  uint8_t supported_raw_fmt_cnt;
  cam_format_t supported_raw_fmts[78];
  uint8_t supported_effects_cnt;
  cam_effect_mode_type supported_effects[12];
  char field_ED8[20];
  uint8_t supported_white_balances_cnt;
  cam_wb_mode_type supported_white_balances[9];
  uint8_t supported_antibandings_cnt;
  cam_antibanding_mode_type supported_antibandings[6];
  uint8_t supported_scene_modes_cnt;
  cam_scene_mode_type supported_scene_modes[19];
  char field_F80[8];
  uint8_t supported_flash_modes_cnt;
  cam_flash_mode_t supported_flash_modes[4];
  uint8_t supported_focus_modes_cnt;
  cam_focus_mode_type supported_focus_modes[7];
  uint8_t supported_iso_modes_cnt;
  cam_iso_mode_type supported_iso_modes[7];
    /* supported auto exposure modes */
    uint8_t supported_aec_modes_cnt;
    cam_auto_exposure_mode_type supported_aec_modes[CAM_AEC_MODE_MAX];
  int supported_focus_algos_cnt;
  cam_focus_algorithm_type supported_focus_algos[4];
  int exposure_compensation_min;
  int exposure_compensation_max;
  int exposure_compensation_default;
  int exposure_compensation_step;
  uint8_t auto_wb_lock_supported;
  uint8_t zoom_supported;
  uint8_t smooth_zoom_supported;
  uint8_t auto_exposure_lock_supported;
  uint8_t video_snapshot_supported;
  uint8_t video_stablization_supported;
  uint8_t max_num_roi;
  uint8_t max_num_focus_areas;
  uint8_t max_num_metering_areas;
  uint8_t max_zoom_step;                /* max zoom step value */
  char field_102B;
  cam_control_range_t brightness_ctrl;
  cam_control_range_t sharpness_ctrl;
  cam_control_range_t contrast_ctrl;
  cam_control_range_t saturation_ctrl;
  cam_control_range_t sce_ctrl;
  char field_107C[40];
  uint32_t qcom_supported_feature_mask;
  cam_padding_info_t padding_info;
  char field_10B1;
  char field_10B2;
  char field_10B3;
  int8_t min_num_hdr_bufs;
  int8_t min_num_pp_bufs;
  char field_10B6;
  char field_10B7;
  uint32_t min_required_pp_mask;
  int used_10BC;
  int used_10C0;
} cam_capability_t;

typedef enum {
    CAM_STREAM_PARAM_TYPE_DO_REPROCESS = CAM_INTF_PARM_DO_REPROCESS,
    CAM_STREAM_PARAM_TYPE_SET_BUNDLE_INFO = CAM_INTF_PARM_SET_BUNDLE,
    CAM_STREAM_PARAM_TYPE_MAX
} cam_stream_param_type_e;

typedef struct {
    uint8_t buf_index;            /* buf index to the source frame buffer that needs reprocess,
                                    (assume buffer is already mapped)*/
    uint32_t frame_idx;           /* frame id of source frame to be reprocessed */
    int32_t ret_val;              /* return value from reprocess. Could have different meanings.
                                     i.e., faceID in the case of face registration. */
    uint8_t meta_present;         /* if there is meta data associated with this reprocess frame */
    uint32_t meta_stream_handle;  /* meta data stream ID. only valid if meta_present != 0 */
    uint8_t meta_buf_index;       /* buf index to meta data buffer. only valid if meta_present != 0 */

    cam_per_frame_pp_config_t frame_pp_config; /* per frame post-proc configuration */
} cam_reprocess_param;

typedef struct {
    cam_stream_param_type_e type;
    union {
        cam_reprocess_param reprocess;  /* do reprocess */
        cam_bundle_config_t bundleInfo; /* set bundle info*/
    };
} cam_stream_parm_buffer_t;

/* stream info */
typedef struct {
    /* stream ID from server */
    uint32_t stream_svr_id;

    /* stream type */
    cam_stream_type_t stream_type;

    /* image format */
    cam_format_t fmt;

    /* image dimension */
    cam_dimension_t dim;

    /* buffer plane information, will be calc based on stream_type, fmt,
       dim, and padding_info(from stream config). Info including:
       offset_x, offset_y, stride, scanline, plane offset */
    cam_stream_buf_plane_info_t buf_planes;

    /* number of stream bufs will be allocated */
    uint8_t num_bufs;

    /* streaming type */
    cam_streaming_mode_t streaming_mode;
    /* num of frames needs to be generated.
     * only valid when streaming_mode = CAM_STREAMING_MODE_BURST */
    uint8_t num_of_burst;

    /* stream specific pp config */
    cam_pp_feature_config_t pp_config;

	// TODO!!! This holds the info for offline reproc which backend reports as "NOT WORKING!!!"
    /* this section is valid if offline reprocess type stream */
    cam_stream_reproc_config_t reprocess_config;

    cam_stream_parm_buffer_t parm_buf;    /* stream based parameters */
} cam_stream_info_t;

/*****************************************************************************
 *                 Code for Domain Socket Based Parameters                   *
 ****************************************************************************/

#define POINTER_OF(PARAM_ID,TABLE_PTR)    \
        (&(TABLE_PTR->entry[PARAM_ID].data))

#define GET_FIRST_PARAM_ID(TABLE_PTR)     \
        (TABLE_PTR->first_flagged_entry)

#define SET_FIRST_PARAM_ID(TABLE_PTR,PARAM_ID)     \
        TABLE_PTR->first_flagged_entry=PARAM_ID

#define GET_NEXT_PARAM_ID(CURRENT_PARAM_ID,TABLE_PTR)    \
        (TABLE_PTR->entry[CURRENT_PARAM_ID].next_flagged_entry)

#define SET_NEXT_PARAM_ID(CURRENT_PARAM_ID,TABLE_PTR,NEXT_PARAM_ID)    \
        TABLE_PTR->entry[CURRENT_PARAM_ID].next_flagged_entry=NEXT_PARAM_ID;

#define INCLUDE(PARAM_ID,DATATYPE,COUNT)  \
        DATATYPE member_variable_##PARAM_ID[ COUNT ]

typedef union {
/**************************************************************************************
 *          ID from (cam_intf_parm_type_t)          DATATYPE                     COUNT
 **************************************************************************************/
    INCLUDE(CAM_INTF_PARM_QUERY_FLASH4SNAP,         int32_t,                     1); //read only

        INCLUDE(CAM_INTF_PARM_EXPOSURE,                 int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_SHARPNESS,                int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_CONTRAST,                 int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_SATURATION,               int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_BRIGHTNESS,               int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_WHITE_BALANCE,            int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_ISO,                      int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_ZOOM,                     int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_ANTIBANDING,              int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_EFFECT,                   int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_FPS_RANGE,                cam_fps_range_t,             1);
    INCLUDE(CAM_INTF_PARM_EXPOSURE_COMPENSATION,    int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_LED_MODE,                 int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_ROLLOFF,                  int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_MODE,                     int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_AEC_ALGO_TYPE,            int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_FOCUS_ALGO_TYPE,          int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_AEC_ROI,                  cam_set_aec_roi_t,           1);
    INCLUDE(CAM_INTF_PARM_AF_ROI,                   cam_roi_info_t,              1);
    INCLUDE(CAM_INTF_PARM_FOCUS_MODE,               int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_BESTSHOT_MODE,            int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_SCE_FACTOR,               int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_FD,                       cam_fd_set_parm_t,           1);
    INCLUDE(CAM_INTF_PARM_AEC_LOCK,                 int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_AWB_LOCK,                 int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_MCE,                      int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_HFR,                      int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_REDEYE_REDUCTION,         int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_WAVELET_DENOISE,          cam_denoise_param_t,         1);
    INCLUDE(CAM_INTF_PARM_HISTOGRAM,                int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_ASD_ENABLE,               int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_RECORDING_HINT,           int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_DIS_ENABLE,               int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_HDR,                      cam_exp_bracketing_t,        1);
    INCLUDE(CAM_INTF_PARM_FRAMESKIP,                int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_ZSL_MODE,                 int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_HDR_NEED_1X,              int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_LOCK_CAF,                 int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_VIDEO_HDR,                int32_t,                     1);
    INCLUDE(CAM_INTF_PARM_UPDATE_RAW,		    cam_dimension_t,		 1);
    INCLUDE(field_24,				    int32_t,			 1); //unknown

    INCLUDE(CAM_INTF_PARM_SAMSUNG_APP, 		    int32_t,			 1);
    INCLUDE(CAM_INTF_PARM_OCRAF_ENABLE, 	    int32_t,			 1);
    INCLUDE(CAM_INTF_PARM_OCRAF_WINDOW,	            int32_t,			 1);
	
    INCLUDE(CAM_INTF_PARM_VISION_MODE,		    int32_t,			 1);
    INCLUDE(CAM_INTF_PARM_VISION_AE,		    int32_t,			 1);
    INCLUDE(field_2F,				    int32_t,			 1); //unknown
    INCLUDE(field_30,				    int32_t,			 1); //unknown
    INCLUDE(CAM_INTF_PARM_DO_REPROCESS,		    int32_t,			 1); //unknown
    INCLUDE(CAM_INTF_PARM_SET_BUNDLE,		    cam_bundle_config_t,	 1);
    INCLUDE(CAM_INTF_PARM_SHOT_MODE,		    int32_t,			 1);
    INCLUDE(CAM_INTF_PARM_ANTISHAKE,		    int32_t,			 1);
    INCLUDE(CAM_INTF_PARM_DUAL_MODE,		    int32_t,			 1);
    INCLUDE(field_36,				    int32_t,			 1); //unknown
    INCLUDE(CAM_INTF_PARM_LLV,			    int32_t,			 1);
    INCLUDE(CAM_INTF_PARM_FIRMWARE_MODE,	    int32_t,			 1);
    INCLUDE(CAM_INTF_PARM_FW_CL_NUMBER,		    cam_fw_cl_number_t,		 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_1,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_2,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_3,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_4,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_5,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_6,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_7,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_8,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_9,		    int,			 1);
    INCLUDE(CAM_INTF_PARM_SAMSUNG_10,		    int,			 1);

    // it now matches the 0xd5 (69) sizeof from the stock cam

} parm_type_t;

/****************************DO NOT MODIFY BELOW THIS LINE!!!!*********************/

typedef struct {
    parm_type_t data;
    uint8_t next_flagged_entry;
} parm_entry_type_t;

typedef struct {
    uint8_t first_flagged_entry;
    parm_entry_type_t entry[CAM_INTF_PARM_MAX];
} parm_buffer_t;

#endif /* __QCAMERA_INTF_H__ */
