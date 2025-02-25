
#ifndef SwaggerComponent_hpp
#define SwaggerComponent_hpp

// #include "oatpp-swagger/ControllerPaths.hpp" See: https://github.com/oatpp/oatpp-swagger/issues/99
#include "oatpp-swagger/Model.hpp"
#include "oatpp-swagger/Resources.hpp"
#include "oatpp/core/macro/component.hpp"

/**
 *  Swagger ui is served at
 *  http://host:port/swagger/ui
 */
class SwaggerComponent {
public:
  
  /**
   *  General API docs info
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::DocumentInfo>, swaggerDocumentInfo)([] {
    
    oatpp::swagger::DocumentInfo::Builder builder;
    
    builder
    .setTitle("Language Playground: C++")
    .setVersion("1.0")
    .setContactName("Galdin Raphael")
    .setContactUrl("https://github.com/gldraphael/lpg")
    .addServer("http://localhost:8000", "server on localhost");
    
    return builder.build();
    
  }());

  // This code needs v1.3.1. See: https://github.com/oatpp/oatpp-swagger/issues/99
//   /**
//    *  Swagger Controller Paths
//    */
//   OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::ControllerPaths>, controllerPaths)([] {
//     auto paths = std::make_shared<oatpp::swagger::ControllerPaths>();
//     paths->apiJson = "docs/openapi.json";       // default is "api-docs/oas-3.0.0.json"
//     paths->ui = "/";                                   // default is "swagger/ui"
//     paths->uiResources = "swagger/{filename}";         // default is "swagger/{filename}"
//     return paths;
//   }());

  
  /**
   *  Swagger-Ui Resources (<oatpp-examples>/lib/oatpp-swagger/res)
   */
  OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::swagger::Resources>, swaggerResources)([] {
    // Make sure to specify correct full path to oatpp-swagger/res folder !!!
    return oatpp::swagger::Resources::loadResources(OATPP_SWAGGER_RES_PATH);
  }());
  
};

#endif /* SwaggerComponent_hpp */
