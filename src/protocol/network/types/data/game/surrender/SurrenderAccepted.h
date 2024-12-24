#ifndef SURRENDERACCEPTED_H
#define SURRENDERACCEPTED_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/surrender/SurrenderResponse.h"
#include "src/utils/io/type/FuncTree.h"

class SurrenderAccepted : public SurrenderResponse
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderAccepted(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderAccepted(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderAccepted(FuncTree tree);
  SurrenderAccepted();
  bool operator==(const SurrenderAccepted &compared);
};

#endif // SURRENDERACCEPTED_H