
#ifndef HelloApiController_hpp
#define HelloApiController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include "../dto/MessageDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * User REST controller.
 */
class HelloApiController : public oatpp::web::server::api::ApiController {
public:
  HelloApiController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {}

public:

  static std::shared_ptr<HelloApiController> createShared(
    OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper) // Inject objectMapper component here as default parameter
  ){
    return std::make_shared<HelloApiController>(objectMapper);
  }

  ENDPOINT_INFO(hello) {
    info->summary = "The \"Hello\" endpoint.";
    info->addTag("exp");

    info->addConsumes<Object<MessageDto>>("application/json");
    info->addResponse<Object<MessageDto>>(Status::CODE_200, "application/json");
  }
  ENDPOINT("GET", "hello", hello) {
    auto msg = MessageDto::createShared();
    msg->message = "Hello, world!";
    
    return createDtoResponse(Status::CODE_200, msg);
  }

  ENDPOINT_INFO(ping) {
    info->summary = "The \"ping\" endpoint.";
    info->addTag("exp");

    info->addConsumes<Object<MessageDto>>("application/json");
    info->addResponse<Object<MessageDto>>(Status::CODE_200, "application/json");
  }
  ENDPOINT("POST", "ping", ping) {
    auto msg = MessageDto::createShared();
    msg->message = "pong";
    
    return createDtoResponse(Status::CODE_200, msg);
  }
  
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif /* HelloApiController_hpp */
