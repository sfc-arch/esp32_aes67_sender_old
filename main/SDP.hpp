#ifndef SDP_HPP

#include <Arduino.h>
#define SDP_HPP

class SDP
{
 private:
   // member variables
   unsigned int _version = 0;
   String _o_username = "";
   String _o_sess_id = "";
   String _o_sess_version = "";
   String _o_nettype = "";
   String _o_addrtype = "";
   String _o_unicast_address = "";
   String _session_name = "";
   String _session_description = "";
   String _uri = "";
   String _email_address = "";
   String _phone_number = "";
   String _c_nettype = ""; // "IN"
   String _c_addrtype = ""; // "IP4" "IP6"
   String _c_connection_address = "";
   String _b_bwtype = "";
   String _b_bandwith = "";
   String _t_start_time = "";
   String _t_stop_time = "";
   String _r_repeat_interval = "";
   String _r_active_duration = "";
   String _r_offset = "";
   String _timezones = ""; // *1
   String _k_method = "";
   String _k_encryption_key = ""; // nil ok
   String _attributes = ""; // *1 in form of "a=xxxx:xxxx\na=yyyy\na=zzzz:zzzz..."
   String _media_descriptions = ""; // *1 "m=aaa bbb ccc ...\nm=xxx yyy zzz ...\na=fff:ggg ..."

   // *1 : these should be created from another class instance

   bool check_required_attributes();

 public:
   // structors
   SDP();
   SDP(String packet);

   // inline

   // getters
   unsigned int version();
   String o_username();
   String o_sess_id();
   String o_sess_version();
   String o_nettype();
   String o_addrtype();
   String o_unicast_address();
   String session_name();
   String session_description();
   String uri();
   String email_address();
   String phone_number();
   String c_nettype();
   String c_addrtype();
   String c_connection_address();
   String b_bwtype();
   String b_bandwith();
   String t_start_time();
   String t_stop_time();
   String r_repeat_interval();
   String r_active_duration();
   String r_offset();
   String timezones();
   String k_method();
   String k_encryption_key();
   String attributes();
   String media_descriptions();

   // setters
   unsigned int set_version(unsigned int version);
   String set_o_username(String o_username);
   String set_o_sess_id(String o_sess_id);
   String set_o_sess_version(String o_sess_version);
   String set_o_nettype(String o_nettype);
   String set_o_addrtype(String o_addrtype);
   String set_o_unicast_address(String o_unicast_address);
   String set_session_name(String session_name);
   String set_session_description(String session_description);
   String set_uri(String uri);
   String set_email_address(String email_address);
   String set_phone_number(String phone_number);
   String set_c_nettype(String c_nettype);
   String set_c_addrtype(String c_addrtype);
   String set_c_connection_address(String c_connection_address);
   String set_b_bwtype(String b_bwtype);
   String set_b_bandwith(String b_bandwith);
   String set_t_start_time(String t_start_time);
   String set_t_stop_time(String t_stop_time);
   String set_r_repeat_interval(String r_repeat_interval);
   String set_r_active_duration(String r_active_duration);
   String set_r_offset(String r_offset);
   String set_timezones(String timezones);
   String set_k_method(String k_method);
   String set_k_encryption_key(String k_encryption_key);
   String set_attributes(String attributes);
   String set_media_descriptions(String media_descriptions);

   String origin();
   String connection_data();
   String bandwith();
   String timing();
   String repeat_times();
   String encryption_keys();

   //others
   String to_string();
};

unsigned int SDP::version(){ return _version; };
String SDP::o_username(){ return _o_username; };
String SDP::o_sess_id(){ return _o_sess_id; };
String SDP::o_sess_version(){ return _o_sess_version; };
String SDP::o_nettype(){ return _o_nettype; };
String SDP::o_addrtype(){ return _o_addrtype; };
String SDP::o_unicast_address(){ return _o_unicast_address; };
String SDP::session_name(){ return _session_name; };
String SDP::session_description(){ return _session_description; };
String SDP::uri(){ return _uri; };
String SDP::email_address(){ return _email_address; };
String SDP::phone_number(){ return _phone_number; };
String SDP::c_nettype(){ return _c_nettype; };
String SDP::c_addrtype(){ return _c_addrtype; };
String SDP::c_connection_address(){ return _c_connection_address; };
String SDP::b_bwtype(){ return _b_bwtype; };
String SDP::b_bandwith(){ return _b_bandwith; };
String SDP::t_start_time(){ return _t_start_time; };
String SDP::t_stop_time(){ return _t_stop_time; };
String SDP::r_repeat_interval(){ return _r_repeat_interval; };
String SDP::r_active_duration(){ return _r_active_duration; };
String SDP::r_offset(){ return _r_offset; };
String SDP::timezones(){ return _timezones; };
String SDP::k_method(){ return _k_method; };
String SDP::k_encryption_key(){ return _k_encryption_key; };
String SDP::attributes(){ return _attributes; };
String SDP::media_descriptions(){ return _media_descriptions; };

unsigned int SDP::set_version(unsigned int version) { _version = version; return _version; };
String SDP::set_o_username(String o_username) { _o_username = o_username; return _o_username; };
String SDP::set_o_sess_id(String o_sess_id) { _o_sess_id = o_sess_id; return _o_sess_id; };
String SDP::set_o_sess_version(String o_sess_version) { _o_sess_version = o_sess_version; return _o_sess_version; };
String SDP::set_o_nettype(String o_nettype) { _o_nettype = o_nettype; return _o_nettype; };
String SDP::set_o_addrtype(String o_addrtype) { _o_addrtype = o_addrtype; return _o_addrtype; };
String SDP::set_o_unicast_address(String o_unicast_address) { _o_unicast_address = o_unicast_address; return _o_unicast_address; };
String SDP::set_session_name(String session_name) { _session_name = session_name; return _session_name; };
String SDP::set_session_description(String session_description) { _session_description = session_description; return _session_description; };
String SDP::set_uri(String uri) { _uri = uri; return _uri; };
String SDP::set_email_address(String email_address) { _email_address = email_address; return _email_address; };
String SDP::set_phone_number(String phone_number) { _phone_number = phone_number; return _phone_number; };
String SDP::set_c_nettype(String c_nettype) { _c_nettype = c_nettype; return _c_nettype; };
String SDP::set_c_addrtype(String c_addrtype) { _c_addrtype = c_addrtype; return _c_addrtype; };
String SDP::set_c_connection_address(String c_connection_address) { _c_connection_address = c_connection_address; return _c_connection_address; };
String SDP::set_b_bwtype(String b_bwtype) { _b_bwtype = b_bwtype; return _b_bwtype; };
String SDP::set_b_bandwith(String b_bandwith) { _b_bandwith = b_bandwith; return _b_bandwith; };
String SDP::set_t_start_time(String t_start_time) { _t_start_time = t_start_time; return _t_start_time; };
String SDP::set_t_stop_time(String t_stop_time) { _t_stop_time = t_stop_time; return _t_stop_time; };
String SDP::set_r_repeat_interval(String r_repeat_interval) { _r_repeat_interval = r_repeat_interval; return _r_repeat_interval; };
String SDP::set_r_active_duration(String r_active_duration) { _r_active_duration = r_active_duration; return _r_active_duration; };
String SDP::set_r_offset(String r_offset) { _r_offset = r_offset; return _r_offset; };
String SDP::set_timezones(String timezones) { _timezones = timezones; return _timezones; };
String SDP::set_k_method(String k_method) { _k_method = k_method; return _k_method; };
String SDP::set_k_encryption_key(String k_encryption_key) { _k_encryption_key = k_encryption_key; return _k_encryption_key; };
String SDP::set_attributes(String attributes) { _attributes = attributes; return _attributes; };
String SDP::set_media_descriptions(String media_descriptions) { _media_descriptions = media_descriptions; return _media_descriptions; };

#endif