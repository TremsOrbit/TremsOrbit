"""

Tristin Houston
thousto2@uvm.edu

Map of Kenya and Rescue Locations!

Pip install folium
Source:
https://www.sheldrickwildlifetrust.org/projects/orphans/rescue-map?q%5Balive%5D=true&q%5Bname%5D=&q%5Bspecies.slug%5D=rhino&q%5Bgender%5D=&q%5Blocation.slug%5D=#raha

"""

import folium


rhino_locations = [
    {"name": "Apollo", "lat": -2.959625, "lon": 38.194843},
    {"name": "Chamboi", "lat": -2.822471, "lon": 38.178364},
    {"name": "Maxwell", "lat": -1.376798, "lon": 36.785252},
    {"name": "Magnum", "lat": -1.384005, "lon": 36.827137},
    {"name": "Solio", "lat": -0.291631, "lon": 36.912614},
    {"name": "Raha", "lat": 0.130764, "lon": 36.784649},
]


kenya_map = folium.Map(location=[0.0236, 37.9062], zoom_start=7)


for rhino in rhino_locations:
    folium.Marker(location=[rhino['lat'], rhino['lon']], popup=rhino['name']).add_to(kenya_map)


kenya_map.save("kenya_rhino_map.html")