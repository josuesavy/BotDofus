#ifndef KNOWNZAAPLISTMESSAGE_H
#define KNOWNZAAPLISTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class KnownZaapListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_KnownZaapListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_KnownZaapListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_KnownZaapListMessage(FuncTree tree);
  KnownZaapListMessage();

  QList<double> destinations;

private:
  void _destinationstreeFunc(Reader *input);
  void _destinationsFunc(Reader *input);

  FuncTree _destinationstree;
};

#endif // KNOWNZAAPLISTMESSAGE_H