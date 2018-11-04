;; Auto-generated. Do not edit!


(when (boundp 'pixart_localization::measured_point)
  (if (not (find-package "PIXART_LOCALIZATION"))
    (make-package "PIXART_LOCALIZATION"))
  (shadow 'measured_point (find-package "PIXART_LOCALIZATION")))
(unless (find-package "PIXART_LOCALIZATION::MEASURED_POINT")
  (make-package "PIXART_LOCALIZATION::MEASURED_POINT"))

(in-package "ROS")
;;//! \htmlinclude measured_point.msg.html


(defclass pixart_localization::measured_point
  :super ros::object
  :slots (_stamp _led_id _led_status _camera_id _point_id _x _y _z ))

(defmethod pixart_localization::measured_point
  (:init
   (&key
    ((:stamp __stamp) (let (r) (dotimes (i 0) (push (instance ros::time :init) r)) r))
    ((:led_id __led_id) (make-array 0 :initial-element 0 :element-type :integer))
    ((:led_status __led_status) (let (r) (dotimes (i 0) (push nil r)) r))
    ((:camera_id __camera_id) (make-array 0 :initial-element 0 :element-type :integer))
    ((:point_id __point_id) (make-array 0 :initial-element 0 :element-type :integer))
    ((:x __x) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:y __y) (make-array 0 :initial-element 0.0 :element-type :float))
    ((:z __z) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _stamp __stamp)
   (setq _led_id __led_id)
   (setq _led_status __led_status)
   (setq _camera_id __camera_id)
   (setq _point_id __point_id)
   (setq _x __x)
   (setq _y __y)
   (setq _z __z)
   self)
  (:stamp
   (&optional __stamp)
   (if __stamp (setq _stamp __stamp)) _stamp)
  (:led_id
   (&optional __led_id)
   (if __led_id (setq _led_id __led_id)) _led_id)
  (:led_status
   (&optional __led_status)
   (if __led_status (setq _led_status __led_status)) _led_status)
  (:camera_id
   (&optional __camera_id)
   (if __camera_id (setq _camera_id __camera_id)) _camera_id)
  (:point_id
   (&optional __point_id)
   (if __point_id (setq _point_id __point_id)) _point_id)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:z
   (&optional __z)
   (if __z (setq _z __z)) _z)
  (:serialization-length
   ()
   (+
    ;; time[] _stamp
    (* 8    (length _stamp)) 4
    ;; int16[] _led_id
    (* 2    (length _led_id)) 4
    ;; bool[] _led_status
    (* 1    (length _led_status)) 4
    ;; int16[] _camera_id
    (* 2    (length _camera_id)) 4
    ;; int16[] _point_id
    (* 2    (length _point_id)) 4
    ;; float64[] _x
    (* 8    (length _x)) 4
    ;; float64[] _y
    (* 8    (length _y)) 4
    ;; float64[] _z
    (* 8    (length _z)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time[] _stamp
     (write-long (length _stamp) s)
     (dotimes (i (length _stamp))
       (write-long (send (elt _stamp i) :sec) s) (write-long (send (elt _stamp i) :nsec) s)
       )
     ;; int16[] _led_id
     (write-long (length _led_id) s)
     (dotimes (i (length _led_id))
       (write-word (elt _led_id i) s)
       )
     ;; bool[] _led_status
     (write-long (length _led_status) s)
     (dotimes (i (length _led_status))
       (if (elt _led_status i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; int16[] _camera_id
     (write-long (length _camera_id) s)
     (dotimes (i (length _camera_id))
       (write-word (elt _camera_id i) s)
       )
     ;; int16[] _point_id
     (write-long (length _point_id) s)
     (dotimes (i (length _point_id))
       (write-word (elt _point_id i) s)
       )
     ;; float64[] _x
     (write-long (length _x) s)
     (dotimes (i (length _x))
       (sys::poke (elt _x i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _y
     (write-long (length _y) s)
     (dotimes (i (length _y))
       (sys::poke (elt _y i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;; float64[] _z
     (write-long (length _z) s)
     (dotimes (i (length _z))
       (sys::poke (elt _z i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time[] _stamp
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _stamp (let (r) (dotimes (i n) (push (instance ros::time :init) r)) r))
     (dolist (elem- _stamp)
     (send elem- :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send elem- :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int16[] _led_id
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _led_id (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _led_id i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; bool[] _led_status
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _led_status (make-list n))
     (dotimes (i n)
     (setf (elt _led_status i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;; int16[] _camera_id
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _camera_id (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _camera_id i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; int16[] _point_id
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _point_id (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _point_id i) (sys::peek buf ptr- :short)) (incf ptr- 2)
     ))
   ;; float64[] _x
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _x (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _x i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _y
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _y (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _y i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;; float64[] _z
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _z (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _z i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get pixart_localization::measured_point :md5sum-) "524275614c80c3a624912649e8f61f71")
(setf (get pixart_localization::measured_point :datatype-) "pixart_localization/measured_point")
(setf (get pixart_localization::measured_point :definition-)
      "time[] stamp
int16[]  led_id
bool[] led_status
int16[]  camera_id
int16[]  point_id
float64[] x
float64[] y
float64[] z

")



(provide :pixart_localization/measured_point "524275614c80c3a624912649e8f61f71")


