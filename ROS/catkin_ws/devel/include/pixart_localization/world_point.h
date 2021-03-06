// Generated by gencpp from file pixart_localization/world_point.msg
// DO NOT EDIT!


#ifndef PIXART_LOCALIZATION_MESSAGE_WORLD_POINT_H
#define PIXART_LOCALIZATION_MESSAGE_WORLD_POINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PointStamped.h>

namespace pixart_localization
{
template <class ContainerAllocator>
struct world_point_
{
  typedef world_point_<ContainerAllocator> Type;

  world_point_()
    : pt()
    , camera_id(0)
    , point_id(0)  {
    }
  world_point_(const ContainerAllocator& _alloc)
    : pt(_alloc)
    , camera_id(0)
    , point_id(0)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::PointStamped_<ContainerAllocator>  _pt_type;
  _pt_type pt;

   typedef uint16_t _camera_id_type;
  _camera_id_type camera_id;

   typedef uint8_t _point_id_type;
  _point_id_type point_id;





  typedef boost::shared_ptr< ::pixart_localization::world_point_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pixart_localization::world_point_<ContainerAllocator> const> ConstPtr;

}; // struct world_point_

typedef ::pixart_localization::world_point_<std::allocator<void> > world_point;

typedef boost::shared_ptr< ::pixart_localization::world_point > world_pointPtr;
typedef boost::shared_ptr< ::pixart_localization::world_point const> world_pointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pixart_localization::world_point_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pixart_localization::world_point_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace pixart_localization

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'pixart_localization': ['/home/ragesh/catkin_ws/src/pixart_localization/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::pixart_localization::world_point_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pixart_localization::world_point_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pixart_localization::world_point_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pixart_localization::world_point_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pixart_localization::world_point_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pixart_localization::world_point_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pixart_localization::world_point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4c1801fffad721cf6519e3411a1948c7";
  }

  static const char* value(const ::pixart_localization::world_point_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4c1801fffad721cfULL;
  static const uint64_t static_value2 = 0x6519e3411a1948c7ULL;
};

template<class ContainerAllocator>
struct DataType< ::pixart_localization::world_point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pixart_localization/world_point";
  }

  static const char* value(const ::pixart_localization::world_point_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pixart_localization::world_point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/PointStamped pt\n\
uint16 camera_id\n\
uint8 point_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PointStamped\n\
# This represents a Point with reference coordinate frame and timestamp\n\
Header header\n\
Point point\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::pixart_localization::world_point_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pixart_localization::world_point_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.pt);
      stream.next(m.camera_id);
      stream.next(m.point_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct world_point_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pixart_localization::world_point_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pixart_localization::world_point_<ContainerAllocator>& v)
  {
    s << indent << "pt: ";
    s << std::endl;
    Printer< ::geometry_msgs::PointStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.pt);
    s << indent << "camera_id: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.camera_id);
    s << indent << "point_id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.point_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PIXART_LOCALIZATION_MESSAGE_WORLD_POINT_H
