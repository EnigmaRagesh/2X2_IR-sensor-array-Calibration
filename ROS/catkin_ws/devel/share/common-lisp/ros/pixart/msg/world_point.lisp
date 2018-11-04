; Auto-generated. Do not edit!


(cl:in-package pixart-msg)


;//! \htmlinclude world_point.msg.html

(cl:defclass <world_point> (roslisp-msg-protocol:ros-message)
  ((pt
    :reader pt
    :initarg :pt
    :type geometry_msgs-msg:PointStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PointStamped))
   (camera_id
    :reader camera_id
    :initarg :camera_id
    :type cl:fixnum
    :initform 0)
   (point_id
    :reader point_id
    :initarg :point_id
    :type cl:fixnum
    :initform 0))
)

(cl:defclass world_point (<world_point>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <world_point>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'world_point)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pixart-msg:<world_point> is deprecated: use pixart-msg:world_point instead.")))

(cl:ensure-generic-function 'pt-val :lambda-list '(m))
(cl:defmethod pt-val ((m <world_point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pixart-msg:pt-val is deprecated.  Use pixart-msg:pt instead.")
  (pt m))

(cl:ensure-generic-function 'camera_id-val :lambda-list '(m))
(cl:defmethod camera_id-val ((m <world_point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pixart-msg:camera_id-val is deprecated.  Use pixart-msg:camera_id instead.")
  (camera_id m))

(cl:ensure-generic-function 'point_id-val :lambda-list '(m))
(cl:defmethod point_id-val ((m <world_point>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pixart-msg:point_id-val is deprecated.  Use pixart-msg:point_id instead.")
  (point_id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <world_point>) ostream)
  "Serializes a message object of type '<world_point>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'pt) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'camera_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'camera_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'point_id)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <world_point>) istream)
  "Deserializes a message object of type '<world_point>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'pt) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'camera_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'camera_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'point_id)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<world_point>)))
  "Returns string type for a message object of type '<world_point>"
  "pixart/world_point")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'world_point)))
  "Returns string type for a message object of type 'world_point"
  "pixart/world_point")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<world_point>)))
  "Returns md5sum for a message object of type '<world_point>"
  "4c1801fffad721cf6519e3411a1948c7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'world_point)))
  "Returns md5sum for a message object of type 'world_point"
  "4c1801fffad721cf6519e3411a1948c7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<world_point>)))
  "Returns full string definition for message of type '<world_point>"
  (cl:format cl:nil "geometry_msgs/PointStamped pt~%uint16 camera_id~%uint8 point_id~%================================================================================~%MSG: geometry_msgs/PointStamped~%# This represents a Point with reference coordinate frame and timestamp~%Header header~%Point point~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'world_point)))
  "Returns full string definition for message of type 'world_point"
  (cl:format cl:nil "geometry_msgs/PointStamped pt~%uint16 camera_id~%uint8 point_id~%================================================================================~%MSG: geometry_msgs/PointStamped~%# This represents a Point with reference coordinate frame and timestamp~%Header header~%Point point~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <world_point>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'pt))
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <world_point>))
  "Converts a ROS message object to a list"
  (cl:list 'world_point
    (cl:cons ':pt (pt msg))
    (cl:cons ':camera_id (camera_id msg))
    (cl:cons ':point_id (point_id msg))
))
