;; Auto-generated. Do not edit!


(when (boundp 'toycode::cam)
  (if (not (find-package "TOYCODE"))
    (make-package "TOYCODE"))
  (shadow 'cam (find-package "TOYCODE")))
(unless (find-package "TOYCODE::CAM")
  (make-package "TOYCODE::CAM"))

(in-package "ROS")
;;//! \htmlinclude cam.msg.html


(defclass toycode::cam
  :super ros::object
  :slots (_x _y _camera_id _point_id _stamp ))

(defmethod toycode::cam
  (:init
   (&key
    ((:x __x) 0)
    ((:y __y) 0)
    ((:camera_id __camera_id) 0)
    ((:point_id __point_id) 0)
    ((:stamp __stamp) (instance ros::time :init))
    )
   (send-super :init)
   (setq _x (round __x))
   (setq _y (round __y))
   (setq _camera_id (round __camera_id))
   (setq _point_id (round __point_id))
   (setq _stamp __stamp)
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:camera_id
   (&optional __camera_id)
   (if __camera_id (setq _camera_id __camera_id)) _camera_id)
  (:point_id
   (&optional __point_id)
   (if __point_id (setq _point_id __point_id)) _point_id)
  (:stamp
   (&optional __stamp)
   (if __stamp (setq _stamp __stamp)) _stamp)
  (:serialization-length
   ()
   (+
    ;; uint16 _x
    2
    ;; uint16 _y
    2
    ;; uint16 _camera_id
    2
    ;; uint8 _point_id
    1
    ;; time _stamp
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _x
       (write-word _x s)
     ;; uint16 _y
       (write-word _y s)
     ;; uint16 _camera_id
       (write-word _camera_id s)
     ;; uint8 _point_id
       (write-byte _point_id s)
     ;; time _stamp
       (write-long (send _stamp :sec) s) (write-long (send _stamp :nsec) s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _x
     (setq _x (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _y
     (setq _y (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _camera_id
     (setq _camera_id (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _point_id
     (setq _point_id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; time _stamp
     (send _stamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get toycode::cam :md5sum-) "b6e378fbcfee096e6fdfd7d90c3f26de")
(setf (get toycode::cam :datatype-) "toycode/cam")
(setf (get toycode::cam :definition-)
      "uint16 x
uint16 y
uint16 camera_id
uint8 point_id
time stamp

")



(provide :toycode/cam "b6e378fbcfee096e6fdfd7d90c3f26de")


