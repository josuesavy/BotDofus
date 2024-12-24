#ifndef PORTALINFORMATION_H
#define PORTALINFORMATION_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/utils/io/type/FuncTree.h"

class PortalInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PortalInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PortalInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PortalInformation(FuncTree tree);
  PortalInformation();
  bool operator==(const PortalInformation &compared);

  int portalId;
  int areaId;

private:
  void _portalIdFunc(Reader *input);
  void _areaIdFunc(Reader *input);
};

#endif // PORTALINFORMATION_H