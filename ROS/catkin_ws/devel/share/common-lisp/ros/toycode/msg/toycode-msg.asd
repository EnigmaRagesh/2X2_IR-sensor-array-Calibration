
(cl:in-package :asdf)

(defsystem "toycode-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "cam" :depends-on ("_package_cam"))
    (:file "_package_cam" :depends-on ("_package"))
  ))