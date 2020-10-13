#ifndef OBJECTAVERAGEPRICESERRORMESSAGE_H
#define OBJECTAVERAGEPRICESERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ObjectAveragePricesErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ObjectAveragePricesErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ObjectAveragePricesErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ObjectAveragePricesErrorMessage(FuncTree tree);
  ObjectAveragePricesErrorMessage();
};

#endif // OBJECTAVERAGEPRICESERRORMESSAGE_H