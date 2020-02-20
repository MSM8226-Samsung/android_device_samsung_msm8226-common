/* capability struct definition */
typedef struct{
    int unknown_1;
    int is_samsung_cam;
    int modes_supported;                                    /* mask of modes supported: 2D, 3D */
    cam_position_t position;                                /* sensor position: front, back */
    uint32_t sensor_mount_angle;                            /* sensor mount angle */

    float focal_length;                                     /* focal length */
    float hor_view_angle;                                   /* horizontal view angle */
    float ver_view_angle;                                   /* vertical view angle */

    uint8_t zoom_ratio_tbl_cnt;                             /* table size for zoom ratios */
    int zoom_ratio_tbl[MAX_ZOOMS_CNT];                      /* zoom ratios table */

    uint8_t preview_sizes_tbl_cnt;                          /* preview sizes table size */
    cam_dimension_t preview_sizes_tbl[MAX_SIZES_CNT];       /* preiew sizes table */

    uint8_t video_sizes_tbl_cnt;                            /* video sizes table size */
    cam_dimension_t video_sizes_tbl[MAX_SIZES_CNT];         /* video sizes table */

    uint8_t picture_sizes_tbl_cnt;                          /* picture sizes table size */
    cam_dimension_t picture_sizes_tbl[MAX_SIZES_CNT];       /* picture sizes table */

    uint8_t fps_ranges_tbl_cnt;                             /* fps ranges table size */
    cam_fps_range_t fps_ranges_tbl[MAX_SIZES_CNT];          /* fps ranges table */

    uint8_t livesnapshot_sizes_tbl_cnt;                     /* livesnapshot sizes table size */
    cam_dimension_t livesnapshot_sizes_tbl[MAX_SIZES_CNT];  /* livesnapshot sizes table */

    uint8_t hfr_tbl_cnt;                                    /* table size for HFR */
    cam_hfr_info_t hfr_tbl[CAM_HFR_MODE_MAX];               /* HFR table */

    /* supported preview formats */
    uint8_t supported_preview_fmt_cnt;
    cam_format_t supported_preview_fmts[CAM_FORMAT_MAX];

    /* supported picture formats */
    uint8_t supported_picture_fmt_cnt;
    cam_format_t supported_picture_fmts[CAM_FORMAT_MAX];

    /* dimension and supported output format of raw dump from camif */
    cam_dimension_t raw_dim;
    uint8_t supported_raw_fmt_cnt;
    cam_format_t supported_raw_fmts[CAM_FORMAT_MAX];

    /* supported effect modes */
    uint8_t supported_effects_cnt;
    cam_effect_mode_type supported_effects[CAM_EFFECT_MODE_MAX];

    /* supported white balance modes */
    uint8_t supported_white_balances_cnt;
    cam_wb_mode_type supported_white_balances[CAM_WB_MODE_MAX];

    /* supported antibanding modes */
    uint8_t supported_antibandings_cnt;
    cam_antibanding_mode_type supported_antibandings[CAM_ANTIBANDING_MODE_MAX];

    /* supported scene modes */
    uint8_t supported_scene_modes_cnt;
    cam_scene_mode_type supported_scene_modes[CAM_SCENE_MODE_MAX];

    /* supported flash modes */
    uint8_t supported_flash_modes_cnt;
    cam_flash_mode_t supported_flash_modes[CAM_FLASH_MODE_MAX];

    /* supported focus modes */
    uint8_t supported_focus_modes_cnt;
    cam_focus_mode_type supported_focus_modes[CAM_FOCUS_MODE_MAX];

    /* supported iso modes */
    uint8_t supported_iso_modes_cnt;
    cam_iso_mode_type supported_iso_modes[CAM_ISO_MODE_MAX];

    /* supported auto exposure modes */
    uint8_t supported_aec_modes_cnt;
    cam_auto_exposure_mode_type supported_aec_modes[CAM_AEC_MODE_MAX];

    /* supported focus algorithms */
    uint8_t supported_focus_algos_cnt;
    cam_focus_algorithm_type supported_focus_algos[CAM_FOCUS_ALGO_MAX];

    int exposure_compensation_min;       /* min value of exposure compensation index */
    int exposure_compensation_max;       /* max value of exposure compensation index */
    int exposure_compensation_default;   /* default value of exposure compensation index */
    float exposure_compensation_step;    /* exposure compensation step value */

    uint8_t auto_wb_lock_supported;       /* flag if auto white balance lock is supported */
    uint8_t zoom_supported;               /* flag if zoom is supported */
    uint8_t smooth_zoom_supported;        /* flag if smooth zoom is supported */
    uint8_t auto_exposure_lock_supported; /* flag if auto exposure lock is supported */
    uint8_t video_snapshot_supported;     /* flag if video snapshot is supported */
    uint8_t video_stablization_supported; /* flag id video stablization is supported */

    uint8_t max_num_roi;                  /* max number of roi can be detected */
    uint8_t max_num_focus_areas;          /* max num of focus areas */
    uint8_t max_num_metering_areas;       /* max num opf metering areas */
    uint8_t max_zoom_step;                /* max zoom step value */

    /* QCOM specific control */
    cam_control_range_t brightness_ctrl;  /* brightness */
    cam_control_range_t sharpness_ctrl;   /* sharpness */
    cam_control_range_t contrast_ctrl;    /* contrast */
    cam_control_range_t saturation_ctrl;  /* saturation */
    cam_control_range_t sce_ctrl;         /* skintone enhancement factor */

    uint32_t qcom_supported_feature_mask; /* mask of qcom specific features supported:
                                           * such as CAM_QCOM_FEATURE_SUPPORTED_FACE_DETECTION*/
    cam_padding_info_t padding_info;      /* padding information from PP */
    int8_t min_num_hdr_bufs;              /* minimum number of buffers needed for HDR by imaging module */
    int8_t min_num_pp_bufs;               /* minimum number of buffers needed by postproc module */
    uint32_t min_required_pp_mask;        /* min required pp feature masks for ZSL.
                                           * depends on hardware limitation, i.e. for 8974,
                                           * sharpness is required for all ZSL snapshot frames */
    int used_10BC;
    int used_10C0;
    int used_10C4;
} cam_capability_t;
