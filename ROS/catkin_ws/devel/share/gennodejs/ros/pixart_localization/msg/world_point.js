// Auto-generated. Do not edit!

// (in-package pixart_localization.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class world_point {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.pt = null;
      this.camera_id = null;
      this.point_id = null;
    }
    else {
      if (initObj.hasOwnProperty('pt')) {
        this.pt = initObj.pt
      }
      else {
        this.pt = new geometry_msgs.msg.PointStamped();
      }
      if (initObj.hasOwnProperty('camera_id')) {
        this.camera_id = initObj.camera_id
      }
      else {
        this.camera_id = 0;
      }
      if (initObj.hasOwnProperty('point_id')) {
        this.point_id = initObj.point_id
      }
      else {
        this.point_id = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type world_point
    // Serialize message field [pt]
    bufferOffset = geometry_msgs.msg.PointStamped.serialize(obj.pt, buffer, bufferOffset);
    // Serialize message field [camera_id]
    bufferOffset = _serializer.uint16(obj.camera_id, buffer, bufferOffset);
    // Serialize message field [point_id]
    bufferOffset = _serializer.uint8(obj.point_id, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type world_point
    let len;
    let data = new world_point(null);
    // Deserialize message field [pt]
    data.pt = geometry_msgs.msg.PointStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [camera_id]
    data.camera_id = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [point_id]
    data.point_id = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += geometry_msgs.msg.PointStamped.getMessageSize(object.pt);
    return length + 3;
  }

  static datatype() {
    // Returns string type for a message object
    return 'pixart_localization/world_point';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4c1801fffad721cf6519e3411a1948c7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    geometry_msgs/PointStamped pt
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new world_point(null);
    if (msg.pt !== undefined) {
      resolved.pt = geometry_msgs.msg.PointStamped.Resolve(msg.pt)
    }
    else {
      resolved.pt = new geometry_msgs.msg.PointStamped()
    }

    if (msg.camera_id !== undefined) {
      resolved.camera_id = msg.camera_id;
    }
    else {
      resolved.camera_id = 0
    }

    if (msg.point_id !== undefined) {
      resolved.point_id = msg.point_id;
    }
    else {
      resolved.point_id = 0
    }

    return resolved;
    }
};

module.exports = world_point;
