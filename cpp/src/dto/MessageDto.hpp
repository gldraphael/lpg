
#pragma once

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class MessageDto : public oatpp::DTO {

  DTO_INIT(MessageDto, DTO)

  DTO_FIELD_INFO(message) {
    info->description = "Message";
  }
  DTO_FIELD(String, message, "msg");
};

#include OATPP_CODEGEN_END(DTO)

