#ifndef SERVEROPTIONALFEATURESMESSAGE_H
#define SERVEROPTIONALFEATURESMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class ServerOptionalFeaturesMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ServerOptionalFeaturesMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ServerOptionalFeaturesMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ServerOptionalFeaturesMessage(FuncTree tree);
  ServerOptionalFeaturesMessage();

  QList<uint> features;

private:
  void _featurestreeFunc(Reader *input);
  void _featuresFunc(Reader *input);

  FuncTree _featurestree;
};

#endif // SERVEROPTIONALFEATURESMESSAGE_H