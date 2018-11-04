;; Auto-generated. Do not edit!


(when (boundp 'pixart_localization::world_point)
  (if (not (find-package "PIXART_LOCALIZATION"))
    (make-package "PIXART_LOCALIZATION"))
  (shadow 'world_point (find-package "PIXART_LOCALIZATION")))
(unless (find-package "PIXART_LOCALIZATION::WORLD_POINT")
  (make-package "PIXART_LOCALIZATION::WORLD_POINT"))

(in-package "ROS")
;;//! \htmlinclude world_point.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass pixart_localization::world_point
  :super ros::object
  :slots (_pt _camera_id _point_id ))

(defmethod pixart_localization::world_point
  (:init
   (&key
    ((:pt __pt) (instance geometry_msgs::PointStamped :init))
    ((:camera_id __camera_id) 0)
    ((:point_id __point_id) 0)
    )
   (send-super :init)
   (setq _pt __pt)
   (setq _camera_id (round __camera_id))
   (setq _point_id (round __point_id))
   self)
  (:pt
   (&rest __pt)
   (if (keywordp (car __pt))
       (send* _pt __pt)
     (progn
       (if __pt (setq _pt (car __pt)))
       _pt)))
  (:camera_id
   (&optional __camera_id)
   (if __camera_id (setq _camera_id __camera_id)) _camera_id)
  (:point_id
   (&optional __point_id)
   (if __point_id (setq _point_id __point_id)) _point_id)
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/PointStamped _pt
    (send _pt :serialization-length)
    ;; uint16 _camera_id
    2
    ;; uint8 _point_id
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/PointStamped _pt
       (send _pt :serialize s)
     ;; uint16 _camera_id
       (write-word _camera_id s)
     ;; uint8 _point_id
       (write-byte _point_id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/PointStamped _pt
     (send _pt :deserialize buf ptr-) (incf ptr- (send _pt :serialization-length))
   ;; uint16 _camera_id
     (setq _camera_id (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _point_id
     (setq _point_id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get pixart_localization::world_point :md5sum-) "4c1801fffad721cf6519e3411a1948c7")
(setf (get pixart_localization::world_point :datatype-) "pixart_localization/world_point")
(setf (get pixart_localization::world_point :definition-)
      "geometry_msgs/PointStamped pt
uint16 camera_id
uint8 point_id

================================================================================
MSG: geometry_msgs/PointStamped
# This represents a Point with reference coordinate frame and timestamp
Header header
Point point

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :pixart_localization/world_point "4c1801fffad721cf6519e3411a1948c7")


