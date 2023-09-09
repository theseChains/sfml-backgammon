#ifndef RESOURCE_HOLDER_HPP
#define RESOURCE_HOLDER_HPP

#include <map>
#include <memory>
#include <string>

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    void load(Identifier identifier, const std::string& fileName);

    Resource& get(Identifier identifier);
    const Resource& get(Identifier identifier) const;

private:
    std::map<Identifier, std::unique_ptr<Resource>> m_resourceMap;
};

#include "ResourceHolder.inl"

#endif
