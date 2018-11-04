// Generated by gencpp from file pixart_localization/measured_point.msg
// DO NOT EDIT!


#ifndef PIXART_LOCALIZATION_MESSAGE_MEASURED_POINT_H
#define PIXART_LOCALIZATION_MESSAGE_MEASURED_POINT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pixart_localization
{
template <class ContainerAllocator>
struct measured_point_
{
  typedef measured_point_<ContainerAllocator> Type;

  measured_point_()
    : stamp()
    , led_id()
    , led_status()
    , camera_id()
    , point_id()
    , x()
    , y()
    , z()  {
    }
  measured_point_(const ContainerAllocator& _alloc)
    : stamp(_alloc)
    , led_id(_alloc)
    , led_status(_alloc)
    , camera_id(_alloc)
    , point_id(_alloc)
    , x(_alloc)
    , y(_alloc)
    , z(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<ros::Time, typename ContainerAllocator::template rebind<ros::Time>::other >  _stamp_type;
  _stamp_type stamp;

   typedef std::vector<int16_t, typename ContainerAllocator::template rebind<int16_t>::other >  _led_id_type;
  _led_id_type led_id;

   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _led_status_type;
  _led_status_type led_status;

   typedef std::vector<int16_t, typename ContainerAllocator::template rebind<int16_t>::other >  _camera_id_type;
  _camera_id_type camera_id;

   typedef std::vector<int16_t, typename ContainerAllocator::template rebind<int16_t>::other >  _point_id_type;
  _point_id_type point_id;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _x_type;
  _x_type x;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _y_type;
  _y_type y;

   typedef std::vector<double, typename ContainerAllocator::template rebind<double>::other >  _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::pixart_localization::measured_point_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::pixart_localization::measured_point_<ContainerAllocator> const> ConstPtr;

}; // struct measured_point_

typedef ::pixart_localization::measured_point_<std::allocator<void> > measured_point;

typedef boost::shared_ptr< ::pixart_localization::measured_point > measured_pointPtr;
typedef boost::shared_ptr< ::pixart_localization::measured_point const> measured_pointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pixart_localization::measured_point_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pixart_localization::measured_point_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::pixart_localization::measured_point_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pixart_localization::measured_point_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pixart_localization::measured_point_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pixart_localization::measured_point_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pixart_localization::measured_point_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pixart_localization::measured_point_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pixart_localization::measured_point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "524275614c80c3a624912649e8f61f71";
  }

  static const char* value(const ::pixart_localization::measured_point_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x524275614c80c3a6ULL;
  static const uint64_t static_value2 = 0x24912649e8f61f71ULL;
};

template<class ContainerAllocator>
struct DataType< ::pixart_localization::measured_point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pixart_localization/measured_point";
  }

  static const char* value(const ::pixart_localization::measured_point_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pixart_localization::measured_point_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time[] stamp\n\
int16[]  led_id\n\
bool[] led_status\n\
int16[]  camera_id\n\
int16[]  point_id\n\
float64[] x\n\
float64[] y\n\
float64[] z\n\
";
  }

  static const char* value(const ::pixart_localization::measured_point_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pixart_localization::measured_point_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.led_id);
      stream.next(m.led_status);
      stream.next(m.camera_id);
      stream.next(m.point_id);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct measured_point_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pixart_localization::measured_point_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pixart_localization::measured_point_<ContainerAllocator>& v)
  {
    s << indent << "stamp[]" << std::endl;
    for (size_t i = 0; i < v.stamp.size(); ++i)
    {
      s << indent << "  stamp[" << i << "]: ";
      Printer<ros::Time>::stream(s, indent + "  ", v.stamp[i]);
    }
    s << indent << "led_id[]" << std::endl;
    for (size_t i = 0; i < v.led_id.size(); ++i)
    {
      s << indent << "  led_id[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.led_id[i]);
    }
    s << indent << "led_status[]" << std::endl;
    for (size_t i = 0; i < v.led_status.size(); ++i)
    {
      s << indent << "  led_status[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.led_status[i]);
    }
    s << indent << "camera_id[]" << std::endl;
    for (size_t i = 0; i < v.camera_id.size(); ++i)
    {
      s << indent << "  camera_id[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.camera_id[i]);
    }
    s << indent << "point_id[]" << std::endl;
    for (size_t i = 0; i < v.point_id.size(); ++i)
    {
      s << indent << "  point_id[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.point_id[i]);
    }
    s << indent << "x[]" << std::endl;
    for (size_t i = 0; i < v.x.size(); ++i)
    {
      s << indent << "  x[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.x[i]);
    }
    s << indent << "y[]" << std::endl;
    for (size_t i = 0; i < v.y.size(); ++i)
    {
      s << indent << "  y[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.y[i]);
    }
    s << indent << "z[]" << std::endl;
    for (size_t i = 0; i < v.z.size(); ++i)
    {
      s << indent << "  z[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.z[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // PIXART_LOCALIZATION_MESSAGE_MEASURED_POINT_H