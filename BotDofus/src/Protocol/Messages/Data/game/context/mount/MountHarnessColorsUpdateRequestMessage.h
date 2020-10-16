#ifndef MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE_H
#define MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class MountHarnessColorsUpdateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MountHarnessColorsUpdateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MountHarnessColorsUpdateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MountHarnessColorsUpdateRequestMessage(FuncTree tree);
  MountHarnessColorsUpdateRequestMessage();

  bool useHarnessColors;

private:
  void _useHarnessColorsFunc(Reader *input);
};

#endif // MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE_H