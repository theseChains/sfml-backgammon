template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier identifier, const std::string& fileName)
{
    auto resource{ std::make_unique<Resource>() };
    if (!resource->loadFromFile(fileName))
        throw std::runtime_error{ "ResourceHolder::load - failed to load " + fileName };

    auto inserted{ m_resourceMap.insert(std::make_pair(identifier, std::move(resource))) };
    assert(inserted.second && "ResourceHolder::load - couldn't insert into resource map");
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier identifier)
{
    auto found{ m_resourceMap.find(identifier) };
    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier identifier) const
{
    auto found{ m_resourceMap.find(identifier) };
    return *found->second;
}
