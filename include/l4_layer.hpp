#pragma once
#include <optional>
#include "layer.hpp"
#include "packets.hpp"

namespace mstack {

class l4_hook : public base_hook_funcs<l4_packet, l4_packet> {
 public:
  void hook_register_protocol(protocol_interface<l4_packet>& in_protocol) {
    DLOG(INFO) << "[REGISTER] " << in_protocol.tag();
    return;
  }

  void hook_dispatch(std::optional<l4_packet>& in_packet) { return; }

  void hook_gather(std::optional<l4_packet>& in_packet) {
    if (!in_packet) {
      return;
    }
    return;
  }
};

using l4_layer = mstack::layer<l4_packet, l4_packet, l4_hook>;

template <>
std::optional<int> get_proto(std::optional<l4_packet>& packet) {
  DLOG(INFO) << "[PROTO L4_PACKET] " << std::setiosflags(std::ios::uppercase)
             << std::hex << packet->_proto;
  return packet->_proto;
}
};  // namespace mstack