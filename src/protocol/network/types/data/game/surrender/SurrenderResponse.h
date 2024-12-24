#ifndef SURRENDERRESPONSE_H
#define SURRENDERRESPONSE_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderResponse : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderResponse(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderResponse(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderResponse(FuncTree tree);
  SurrenderResponse();
  bool operator==(const SurrenderResponse &compared);
};

#endif // SURRENDERRESPONSE_H