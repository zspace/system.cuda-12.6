async function _populateSocialMediaIcons()
{
    // helper to grab a url and convert it to a js object
    async function _fetchJson(url)
    {
        console.log(`fetching: ${url}`)
        let response = await fetch(url)
        if (!response.ok)
        {
            throw Error(`unable to retrieve ${url}: ${response.status}`)
        }

        return response.json()
    }

    try
    {
        // sphinx happily puts a relative path to the project root in each of its html files :)
        const root = document.getElementById("documentation_options").getAttribute('data-url_root')
        if (!root)
        {
            throw new Error("unable to find data-url_root in header")
        }

        // grab project information
        const project = await _fetchJson(`${root}project.json`)

        const site2icon = {
            "youtube": 'youtube-play',
            "www": 'globe',
            "linkedin": 'linkedin-square',
            "facebook": 'facebook-official',
            "bitbucket": 'bitbucket-square',
        }

        if (!("social_media" in project) || (project.social_media.length < 1))
        {
            console.log("project does not define 'social_media'.  no social media icon will be shown.")
            return
        }

        const elems = document.querySelectorAll("li.wy-breadcrumbs-aside")
        if (elems.length < 1)
        {
            console.log("could not find breadcrumb aside to place social media icons")
            return
        }

        const elem = elems[0]
        elem.classList.add("fa")

        html = ""
        for (let i = 0; i < project.social_media.length; i++)
        {
            sm = project.social_media[i]

            let site = encodeURIComponent(sm.site)
            let url = encodeURI(sm.url)

            if (site in site2icon)
            {
                site = site2icon[site] ?? site;
            }

            spanElement = document.createElement('span');
            spanElement.classList.add('social-media-icon');

            linkElement = document.createElement('a');
            linkElement.href = url;

            iconElement = document.createElement('i');
            iconElement.classList.add('fa', `fa-${site}`);

            linkElement.appendChild(iconElement);
            spanElement.appendChild(linkElement);
            elem.appendChild(spanElement);
        }
    }
    catch (e)
    {
        console.log("warning: failed to populate social media icons:", e)
    }
}

// wait until the page is loaded to modify the DOM
window.addEventListener("load", _populateSocialMediaIcons)
