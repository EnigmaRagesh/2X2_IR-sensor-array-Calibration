
(cl:in-package :asdf)

(defsystem "pixart_localization-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "measured_point" :depends-on ("_package_measured_point"))
    (:file "_package_measured_point" :depends-on ("_package"))
    (:file "world_point" :depends-on ("_package_world_point"))
    (:file "_package_world_point" :depends-on ("_package"))
  ))