#include "SDP.hpp"

SDP::SDP() {};
SDP::SDP(String packet) {};
/**
   SDP::SDP(
      unsigned int version,
      String o_username,
      String o_sess_id,
      String o_sess_version,
      String o_nettype,
      String o_addrtype,
      String o_unicast_address,
      String session_name,
      String session_description,
      String uri,
      String email_address,
      String phone_number,
      String c_nettype,
      String c_addrtype,
      String c_connection_address,
      String b_bwtype,
      String b_bandwith,
      String t_start_time,
      String t_stop_time,
      String r_repeat_interval,
      String r_active_duration,
      String r_offset,
      String timezones,
      String k_method,
      String encryption_key,
      String attributes = "",
      String media_descriptions
   )
   {
      _o_username = o_username;
      _o_sess_id = o_sess_id;
      _o_sess_version = o_sess_version;
      _o_nettype = o_nettype;
      _o_addrtype = o_addrtype;
      _o_unicast_address = o_unicast_address;
      _session_name = session_name;
      _session_description = session_description;
      _uri = uri;
      _email_address = email_address;
      _phone_number = phone_number;
      _c_nettype = c_nettype;
      _c_addrtype = c_addrtype;
      _c_connection_address = c_connection_address;
      _b_bwtype = b_bwtype;
      _b_bandwith = b_bandwith;
      _t_start_time = t_start_time;
      _t_stop_time = t_stop_time;
      _r_repeat_interval = r_repeat_interval;
      _r_active_duration = r_active_duration;
      _r_offset = r_offset;
      _timezones = timezones;
      _k_method = k_method;
      _encryption_key = encryption_key;
      _attributes = attributes;
      _media_descriptions = media_descriptions;
   };
 *
 */

String SDP::origin()
{
   String origin = "";
   origin += _o_username;
   origin += " ";
   origin += _o_sess_id;
   origin += " ";
   origin += _o_sess_version;
   origin += " ";
   origin += _o_nettype;
   origin += " ";
   origin += _o_unicast_address;
   return origin;
};
String SDP::connection_data()
{
   String connection_data = "";
   connection_data += _c_nettype;
   connection_data += " ";
   connection_data += _c_addrtype;
   connection_data += " ";
   connection_data += _c_connection_address;
   return connection_data;
};
String SDP::bandwith()
{
   String bandwith = "";
   bandwith += _b_bwtype;
   bandwith += ":";
   bandwith += _b_bandwith;
   return bandwith;
};
String SDP::timing()
{
   String timing = "";
   timing += _t_start_time;
   timing += " ";
   timing += _t_stop_time;
   return timing;
};
String SDP::repeat_times()
{
   String repeat = "";
   repeat += _r_repeat_interval;
   repeat += " ";
   repeat += _r_active_duration;
   repeat += " ";
   repeat += _r_offset;
   return repeat;
};
String SDP::encryption_keys()
{
   String keys = "";
   keys += _k_method;
   if (_k_encryption_key = "")
   {
      keys += " ";
      keys += _k_encryption_key;
   };
   return keys;
};

bool SDP::check_required_attributes()
{
   return 
   // _version is always valid
   _o_username != "" &&
   _o_sess_id != "" &&
   _o_sess_version != "" &&
   _o_nettype != "" &&
   _o_addrtype != "" &&
   _o_unicast_address != "" &&
   _session_name != "" &&
   _t_start_time != "" &&
   _t_stop_time != "";
};


String SDP::to_string()
{
   if (check_required_attributes())
   {
      String result = "";

      result += "v=";
      result += _version;
      result += "\no=";
      result += origin();
      result += "\ns=";
      result += _session_name;
      if (_session_description != "")
      {
         result += "\ni=";
         result += _session_description;
      };
      if (_uri != "")
      {
         result += "\nu=";
         result += _uri;
      };
      if (_email_address != "")
      {
         result += "\ne=";
         result += _email_address;
      };
      if (_phone_number != "")
      {
         result += "\np=";
         result += _phone_number;
      };
      if (connection_data() != "")
      {
         result += "\nc=";
         result += connection_data();
      };
      if (bandwith() != "")
      {
         result += "\nb=";
         result += bandwith();
      };
      result += "\nt=";
      result += timing();
      if (repeat_times() != "")
      {
         result += "\nr=";
         result += repeat_times();
      };
      if (_timezones != "")
      {
         result += "\nz=";
         result += _timezones;
      };
      if (encryption_keys() != "")
      {
         result += "\nk=";
         result += encryption_keys();
      };
      if (_attributes != "")
      {
         result += "\n";
         result += _attributes;
      }; // includes "a="
      if (_media_descriptions != "")
      {
         result += "\n";
         result += _media_descriptions;
      };

      return result;
   } else {
      return String("");
   };
};
