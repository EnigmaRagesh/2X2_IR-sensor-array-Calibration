
(cl:in-package :asdf)

(defsystem "pixart-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "raw_point" :depends-on ("_package_raw_point"))
    (:file "_package_raw_point" :depends-on ("_package"))
    (:file "world_point" :depends-on ("_package_world_point"))
    (:file "_package_world_point" :depends-on ("_package"))
  ))